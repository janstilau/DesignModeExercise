//
//  main.m
//  Command
//
//  Created by jansti on 2017/8/30.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import <Foundation/Foundation.h>

NSMutableDictionary *_dict;

void init(){
    _dict = [[NSMutableDictionary alloc] init];
}

@interface MyCommand : NSObject

- (void)redo;
- (void)undo;

@end

@implementation MyCommand

- (void)redo {
    
}

- (void)undo {
    
}

@end

@interface AddCommand :MyCommand

- (instancetype)initWithKey:(NSString *)key value:(id)value;

@end

@implementation AddCommand
{
    NSString *_key;
    id _cacheValue;
    id _newValue;
}

- (instancetype)initWithKey:(NSString *)key value:(id)value {
    self = [super init];
    if (self) {
        _key = key;
        _cacheValue = _dict[key];
        _newValue = value;
    }
    return self;
}

- (void)redo {
    _dict[_key] = _newValue;
}

- (void)undo {
    _dict[_key] = _cacheValue;
}

@end

@interface DeleteCommand :MyCommand

- (instancetype)initWithKey:(NSString *)key;

@end

@implementation DeleteCommand
{
    NSString *_key;
    id _cacheValue;
}

- (instancetype)initWithKey:(NSString *)key {
    self = [super init];
    if (self) {
        _key = key;
        _cacheValue = _dict[key];
    }
    return self;
}

- (void)redo {
    [_dict removeObjectForKey:_key];
}

- (void)undo {
    _dict[_key] = _cacheValue;
}

@end

@interface ReplaceCommand : MyCommand

- (instancetype)initWithReplaceDict:(NSDictionary *)dict;

@end

@implementation ReplaceCommand
{
    NSDictionary *_newValue;
    NSDictionary *_cacheValue;
}

- (instancetype)initWithReplaceDict:(NSDictionary *)dict {
    self = [super init];
    if (self) {
        _newValue = dict;
        NSMutableDictionary *cache = [[NSMutableDictionary alloc] init];
        for (NSString *key in _newValue) {
            id value = _dict[key];
            if (!value) { value = [NSNull null]; }
            cache[key] = value;
        }
        _cacheValue = [cache copy];
    }
    return self;
}

- (void)redo {
    
    for (NSString *key in _newValue) {
        _dict[key] = _newValue[key];
    }
}

- (void)undo {
    
    for (NSString *key in _cacheValue) {
        _dict[key] = _cacheValue[key];
        if (_dict[key] == [NSNull null]) {
            [_dict removeObjectForKey:key];
        }
    }
}

@end

@interface MyCommandStack : NSObject

- (void)addCommand:(MyCommand *)command;
- (void)setCommandIndex:(int) index;

@end

@interface MyCommandStack ()

@property (nonatomic, strong) NSMutableArray *stack;
@property (nonatomic, assign) int index;

@end

@implementation MyCommandStack

- (instancetype)init {
    self = [super init];
    if (self) {
        _stack = [[NSMutableArray alloc] init];
        _index = -1;
    }
    return self;
}

- (void)addCommand:(MyCommand *)command {
    if (_index < _stack.count - 1) {
        while (_stack.count != _index + 1) {
            [_stack removeLastObject];
        }
    }
    [_stack addObject:command];
    [command redo];
    _index++;
    NSLog(@"%@", _dict);
}

- (void)setCommandIndex:(int)index {
    
    int count = (int)_stack.count;
    if (index >= count) { NSAssert(FALSE, @"index pass the command count"); };
    if (index < -1) { NSAssert(FALSE, @"the smallest index is -1");  }
    
    if (index > _index) {
        for (int i = _index; i < index; i++) {
            MyCommand *command = _stack[i];
            [command redo];
        }
    } else if ( index < _index) {
        for (int i = _index; i > index; i--) {
            MyCommand *command = _stack[i];
            [command undo];
        }
    }
    
    _index = index;
    NSLog(@"%@", _dict);
}

@end


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        init();
        
        MyCommandStack *stack = [[MyCommandStack alloc] init];
        
        [stack addCommand: [[AddCommand alloc] initWithKey:@"1" value:@"1"]]; // 0
        [stack addCommand: [[AddCommand alloc] initWithKey:@"2" value:@"2"]]; // 1
        [stack addCommand: [[AddCommand alloc] initWithKey:@"1" value:@"1"]]; // 2
        [stack addCommand:[[ReplaceCommand alloc] initWithReplaceDict:@{@"new": @"newValue",
                                                                        @"1" : @"100" }]]; // 3
        [stack setCommandIndex:2];
    }
    return 0;
}
