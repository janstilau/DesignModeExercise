//
//  ArrayList.m
//  DesignMode
//
//  Created by jansti on 2017/8/26.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import "ArrayList.h"

@interface ArrayIt : NSObject <MyIterator>

@property (nonatomic, assign) int index;
@property (nonatomic, weak) NSMutableArray *container;

- (instancetype)initWithContainer:(NSMutableArray *)container;
@end

@implementation ArrayIt

- (instancetype)initWithContainer:(NSMutableArray *)container {
    
    self = [super init];
    if (self) {
        _container = container;
        _index = 0;
    }
    return self;
}

- (BOOL)hasNext {
    
    return _index < _container.count;
}

- (NSObject *)nextObject {
    
    NSObject *obj = [_container objectAtIndex:_index];
    _index ++;
    return obj;
}

@end

@interface ArrayList ()

@property (nonatomic, strong) NSMutableArray *array;


@end

@implementation ArrayList

- (instancetype)init {
    
    self = [super init];
    if (self) {
        _array = [[NSMutableArray alloc] init];
    }
    return self;
}

- (int)size {
    
    return (int)_array.count;
}

- (void)addObject:(id)object {
    
    [_array addObject:object];
}

- (void)removeobject:(id)object {
    
    [_array enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if (obj == object) {
            [_array removeObjectAtIndex:idx];
            *stop = YES;
        }
    }];
}

- (id<MyIterator>)iterator {
    
    return [[ArrayIt alloc] initWithContainer:_array];;
}

@end
