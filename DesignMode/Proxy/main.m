//
//  main.m
//  Proxy
//
//  Created by justin lau on 2017/8/30.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import <Foundation/Foundation.h>


NSMutableArray *_cache;

@interface RefCountObj : NSObject

@property (nonatomic, assign) int refCount;
@property (nonatomic, strong) id value;

@end

@implementation RefCountObj

- (instancetype)initWithValue:(id)value {
   self = [super init];
    if (self) {
        _refCount = 1;
        if (!_cache) {
            _cache = [[NSMutableArray alloc] init];
            _value = value;
        }
        [_cache addObject:self];
    }
    return self;
}

- (void)setRefCount:(int)refCount {
    
    _refCount = refCount;
    if (!refCount){
        [_cache removeObject:self];
    }
}

@end

@interface RefObjProxy : NSObject

@property (nonatomic, weak) RefCountObj *obj;
@property (nonatomic, strong) id value;

- (instancetype)initWithValue:(id)value;
- (instancetype)initWithProxy:(RefObjProxy *)proxy;

@end

@implementation RefObjProxy

- (id)value {
    return _obj.value;
}

- (void)setValue:(id)value {
    
    _obj.refCount = _obj.refCount - 1;
    _obj = [[RefCountObj alloc] initWithValue:value];
}

- (instancetype)initWithValue:(id)value {
    self = [super init];
    if (self) {
        _obj = [[RefCountObj alloc] initWithValue:value];
    }
    return self;
}

- (instancetype)initWithProxy:(RefObjProxy *)proxy {
    self = [super init];
    if (self) {
        _obj = proxy.obj;
        _obj.refCount += 1;
    }
    return self;
}

- (void)dealloc {
    
    _obj.refCount -= 1;
}

@end


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        RefObjProxy *proxy = [[RefObjProxy alloc] initWithValue:@"1"];
        NSLog(@"%@", _cache);
        {
        RefObjProxy *proxy_2 = [[RefObjProxy alloc] initWithValue:@"1"];
        NSLog(@"%@", _cache);
        RefObjProxy *proxy_3 = [[RefObjProxy alloc] initWithProxy:proxy_2];
        NSLog(@"%@", _cache);
        
        proxy_3.value = @"2";
        NSLog(@"%@", _cache);
        }
        
        NSLog(@"%@", _cache);
        
        
    }
    return 0;
}
