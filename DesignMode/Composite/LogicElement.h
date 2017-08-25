//
//  LogicElement.h
//  DesignMode
//
//  Created by jansti on 2017/8/25.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LogicElement : NSObject

@property (nonatomic, weak) LogicElement* parent;
@property (nonatomic, strong, readonly) NSArray<LogicElement *> *children;

// c++里面,removeChild还有一个bool代表要不要delete.因为,c++里面需要手动delete掉堆空间数据
// 而在实际的删除,是在command里面. 在oc环境下,command可以强引用被删除的logicElement,这样在command销毁的时候,也能销毁.
- (void)removeChild:(LogicElement *)child;
// 为什么要有这个呢,主要用在了remove,moveCommand里面. 在undo的时候,需要回退到原来的状态,这样,index就是比较重要的数据了
- (int)indexOfChild:(LogicElement *)child;
- (void)addChild:(LogicElement *)child;
/* 这个方法,在c++里面设置为虚方法,也就是需要子类特殊化的.在primitive类里面,直接assert,在composite里面,进行children的插入
 操作.addChild 是调用了insertChild. c++这种可以重写的方法必须设置为虚函数的方式,倒是更好的管理了代码.insert作为唯一的入口,
 在这里卡死就可以了.oc可以重写addChild方法,反而增加了危险.
*/
- (void)insertChildInIndex:(int)index child:(LogicElement *)child;
- (bool)isParentOrSuperParent:(LogicElement *)element;
- (bool)traverseChildren:(bool (^)(LogicElement *)) func;
- (bool)traverseChildrenReversely:(bool (^)(LogicElement *)) func;

+ (NSArray<LogicElement *> *)cleanSelection: (NSArray<LogicElement *> *) originSelection;

@end
