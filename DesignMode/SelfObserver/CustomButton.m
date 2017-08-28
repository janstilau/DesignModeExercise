//
//  MyButton.m
//  DesignMode
//
//  Created by justin lau on 2017/8/27.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import "CustomButton.h"

@implementation CustomButton

- (instancetype)init {
    self = [super init];
    if(self) {
        _cache = [[NSMutableDictionary alloc] init];
    }
    return self;
}

- (void)addTarget:(id)target aciton:(NSString *)action forEvent:(int)event
{
    if (!target) { return; }
    if (action.length == 0) { return; }
    if (event < 0) { return; }

    NSMapTable<id, NSMutableArray<NSString *> *> *eventMap = [_cache objectForKey:@(event)];
    if (!eventMap) {
        eventMap = [NSMapTable weakToStrongObjectsMapTable];
        [_cache setObject:eventMap forKey:@(event)];
    }
    NSMutableArray<NSString *> *selectorArray = [eventMap objectForKey:target];
    if (!selectorArray) {
        selectorArray = [[NSMutableArray alloc] init];
        [eventMap setObject:selectorArray forKey:target];
    }
    [selectorArray addObject:action];
}

- (void)trigger:(int)event{
    
    NSMapTable<id, NSMutableArray<NSString *> *> *eventMap = [_cache objectForKey:@(event)];
    if (!eventMap.count) { return; }
    
    for (id obj in eventMap) {
        NSArray<NSString *> *selectorArray = [eventMap objectForKey:obj];
        for (NSString *selector in selectorArray) {
            SEL action = NSSelectorFromString(selector);
            [obj performSelector:action withObject:self];
        }
    }
}

@end
