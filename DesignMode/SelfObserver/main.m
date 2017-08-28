//
//  main.m
//  SelfObserver
//
//  Created by justin lau on 2017/8/27.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CustomButton.h"
#import <Foundation/Foundation.h>

@interface MyNotification : NSObject

@property (nonatomic, strong) id object;
@property (nonatomic, strong) NSDictionary *userInfo;

@end

@implementation MyNotification

@end




@interface MyCenter : NSObject

@property (nonatomic, strong) NSMutableDictionary<NSString *, NSMapTable<id, NSMutableArray<NSString *>*> *> *cache;
@property (nonatomic, strong) NSMutableDictionary<NSString *, NSMutableArray<NSString *> *> *objRegister;

- (void)addObserver:(id)obj selector:(NSString *)selector name:(NSString *)name object:(id)obj;
- (void)postNotificationName:(NSString *)name object:(id)obj userInfo:(NSDictionary *)userInfo;
- (void)removeObserver:(id)observer name:(NSString *)name object:(id)obj;

@end



@interface MyCenter ()



@end

@implementation MyCenter

- (instancetype)init {
    self = [super init];
    if (self) {
        _cache = [[NSMutableDictionary alloc] init];
        _objRegister = [[NSMutableDictionary alloc] init];
    }
    return self;
}

- (void)addObserver:(id)obj selector:(NSString *)selector name:(NSString *)name object:(id)sender {
    
    if (!obj || !selector.length || !name.length) { return; }
    
    NSString *key = [NSString stringWithFormat:@"%p%@", sender, name];
    if([key hasPrefix:@"0x0"]) { key = [key substringFromIndex:[@"0x0" length]]; };
    NSMapTable<id, NSMutableArray<NSString *>*> *objActionMap = _cache[key];
    if (!objActionMap) {
        objActionMap = [NSMapTable weakToStrongObjectsMapTable];
        _cache[key] = objActionMap;
    }
    NSMutableArray<NSString *> *actions = [objActionMap objectForKey:obj];
    if (!actions) {
        actions = [[NSMutableArray alloc] init];
        [objActionMap setObject:actions forKey:obj];
    }
    if ([actions containsObject:selector]) { return; }
    [actions addObject:selector];
    
    NSString *observerAdd = [NSString stringWithFormat:@"%p", obj];
    NSMutableArray<NSString *> *addresses = _objRegister[observerAdd];
    if (!addresses) {
        addresses = [[NSMutableArray alloc] init];
        _objRegister[observerAdd] = addresses;
    }
    if (![addresses containsObject:key]) {
        [addresses addObject:key];
    }
}

- (void)postNotificationName:(NSString *)name object:(id)obj userInfo:(NSDictionary *)userInfo {
    
    if (!name.length) { return; }
    NSString *key = [NSString stringWithFormat:@"%p%@", obj, name];
    if([key hasPrefix:@"0x0"]) { key = [key substringFromIndex:[@"0x0" length]]; };
    
    NSMapTable<id, NSMutableArray<NSString *>*> *objActionMap = _cache[key];
    if (!objActionMap) { return; }
    
    for (id observer in objActionMap) {
        NSArray *actions = [objActionMap objectForKey:observer];
        for (NSString *selector in actions ) {
            MyNotification *noti = [[MyNotification alloc] init];
            noti.object = obj;
            noti.userInfo = userInfo;
            [observer performSelector:NSSelectorFromString(selector) withObject:noti];
        }
    }
}

- (void)removeObserver:(id)observer name:(NSString *)name object:(id)obj {
    
    if (!observer) { return ; }
    
    NSString *observerAdd = [NSString stringWithFormat:@"%p", observer];
    NSMutableArray *keyArray = _objRegister[observerAdd];
    // 这里有设计问题,按照理解,可以指给出name,也可以只给出obj.只给出name,应该去除observer对于name的监听,不管poster是谁.
    // 但是现在的name,obj必须要一起给出才行.可以用contains的办法,但是这样,如果一个name就是contains了另一个name,那就有问题了.
    
    NSMutableString *key = [[NSString stringWithFormat:@"%p", obj] mutableCopy];
    if([key hasPrefix:@"0x0"]) { [key deleteCharactersInRange:NSMakeRange(0, 3)]; };
    if(name) { [key appendString:name]; }
    
    NSMutableArray<NSString *> *deleteArray = [[NSMutableArray alloc] init];
    for (NSString *item in keyArray) {
        if (key.length) {
            if ([item containsString:key]) {
                [deleteArray addObject:item];
            }
        } else {
            [deleteArray addObject:item];
        }
    }
    
    for (NSString *item in deleteArray) {
        NSMapTable<id, NSMutableArray<NSString *>*> *map = _cache[item];
        [map removeObjectForKey:observer];
        if (![map count]) {
            [_cache removeObjectForKey:item];
        }
    }
    
    for (NSString *item in deleteArray) {
        [keyArray removeObject:item];
    }
    if (!keyArray.count) {
        [_objRegister removeObjectForKey:observerAdd];
    }
}

@end

@interface Controller : NSObject

- (void)btnClick:(id)trigger;

@end

@implementation Controller

- (void)btnClick:(id)trigger {
    NSLog(@"%@", trigger);
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        Controller *observer = [[Controller alloc] init];
        Controller *observer_2 = [[Controller alloc] init];
        
        NSObject *poster = [[NSObject alloc] init];
        MyCenter *center = [[MyCenter alloc] init];
        [center addObserver:observer selector:@"btnClick:" name:@"TempNotification" object:poster];
        [center addObserver:observer_2 selector:@"btnClick:" name:@"TempNotification" object:poster];
        [center addObserver:observer selector:@"btnClick:" name:@"TempNotification" object:nil];
        NSLog(@"%@", center.cache);
        NSLog(@"%@", center.objRegister);
        [center removeObserver:observer name:nil object:nil];
        NSLog(@"%@", center.cache);
        NSLog(@"%@", center.objRegister);

//        NSLog(@"%@", center.cache);
//        NSLog(@"%@", center.objRegister);
//        NSDictionary *dict = @{ @"1" : @"1value",};
//        [center postNotificationName:@"TempNotification" object:poster userInfo:dict];
        
    }
    return 0;
}
