//
//  main.m
//  Template Method
//
//  Created by jansti on 2017/8/24.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TemplateSub.h"

// 模板方法是一个非常常用的方法模式.
/* 在无论哪个类库里面,类的编写者一定是这样编写函数的.
    有个方法的逻辑比较复杂,需要其他方法的配合,那么在这个方法里面,先调用某个方法,然后调用某个
 方法. 这样的一套逻辑是编写者定好的,也是符合类的编写初衷的.
    但是,里面有些方法,例如准备数据,是可以交由子类进行配置的.也就是说,一套固定的调用顺序里面
 可以有一些方法被重写.
    于是子类重新定义这些方法,对象的行为也就会改变.
    我们平时在编写代码的时候,不就是这么进行编程的.View:: SizeToFit 方法不能够达到我们的
 需求,重写,然后view就可以到达合适的size.touchesBegin方法需要增加功能,重写,于是view的触摸
 方法就有了新的功能.但是这些功能的调用是在类的另外一个方法里面,这个方法里面的调用顺序是固定的.
 我们重写某些方法,其实就是改变那个方法某个调用的效果.那个方法的调用顺序还是固定的.
 */

/*
    在oc里面,重写是一个非常普遍的行为,因为没有虚函数的这个概念.oc的动态特性,使得每一个方法都
 会被重写.于是,所有的函数,都可以重新定义功能.这个时候,为了维护apple定义的功能,不要忘记super 
 invoke.除非文档里明确说出,这个方法do nothing.但是,谁能记住所有的do nothing 的方法.
 */

/*
    在c++中,因为虚函数是需要特地的指明的,模板方法更能体现原始的功能
 当不变和可变的行为在方法的子类实现中混合在一起的时候,不变的行为就会在子类中重复出现.通过模板
 方法,可以把这些行为搬到单一的地方,可以帮助子类摆脱重复不变行为的纠缠.
 A operation 1,2,3,4,5,6,7
 B operation 1,3,4,5,7,8,9,
 super operation 1 [hook operation2] 3,4,5,[hook operation6],7[hook operation89]
 然后A, B 各自实现自己的hook operation.
 如果不用模板方法抽取,那么其实,A,B都需要知道执行某个opeation的调用逻辑的.这对子类负担太大,
 经过抽取,逻辑不暴露给子类.而且重复代码也只写在了父类上.
 
 when common behavior among subclasses should be factored and localized in a common class to avoid code duplication. This is a good example of "refactoring to generalize" as described by Opdyke and Johnson [OJ93]. You first identify the differences in the existing code and then separate the differences into new operations. Finally, you replace the differing code with a template method that calls one of these new operations.
 */


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        [[[TemplateSuper alloc] init] operation];
        [[[TemplateSub alloc] init] operation];
        
    }
    return 0;
}
