//
//  Container.h
//  DesignMode
//
//  Created by jansti on 2017/8/26.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef Container_h
#define Container_h

@protocol MyIterator <NSObject>

@required
- (NSObject *)nextObject;
- (BOOL)hasNext;

@end



@protocol Container <NSObject>

@required
- (void)addObject:(id)object;
- (id<MyIterator>)iterator;
@property (nonatomic, assign, readonly) int size;

@optional
- (void)removeobject:(id)object;


@end


#endif /* Container_h */
