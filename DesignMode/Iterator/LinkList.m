//
//  LinkList.m
//  DesignMode
//
//  Created by jansti on 2017/8/26.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import "LinkList.h"

@interface LinkNode : NSObject

@property (nonatomic, strong) id value;
@property (nonatomic, strong) LinkNode *next;
- (instancetype)initWithValue:(id)value;

@end

@implementation LinkNode

- (instancetype)initWithValue:(id)value {
    self = [super init];
    if (self) {
        _value = value;
    }
    return self;
}

@end

@interface LinkIterator : NSObject<MyIterator>

@property (nonatomic, weak) LinkNode *current;

- (instancetype)initWithHeadNode:(LinkNode *)head;

@end

@implementation LinkIterator

- (instancetype)initWithHeadNode:(LinkNode *)head {
    self = [super init];
    if (self) {
        _current = head;
    }
    return self;
}

- (BOOL)hasNext {
    
    return _current ? true: false;
}


- (NSObject *)nextObject {
    
    id value = _current.value;
    _current = _current.next;
    return value;
}


@end


@interface LinkList ()

@property (nonatomic, assign) int size;
@property (nonatomic, strong) LinkNode *head;
@property (nonatomic, strong) LinkNode *tail;

@end

@implementation LinkList

- (void)addObject:(id)object {
    
    if (!object) { return; }
    
    LinkNode *node = [[LinkNode alloc] initWithValue:object];
    if (!_head || !_tail) {
        _head = _tail = node;
    } else {
        _tail.next = node;
        _tail = node;
    }
    _size++;
}

- (void)removeobject:(id)object {
    
    if (!object) { return; }
    if (!_head || !_tail) { return; }
    if (_head.value == object) {
        if (_tail == _head) {
            _tail = NULL;
        }
        _head = _head.next;
        _size--;
        return;
    }
    
    LinkNode *node = _head;
    while (node) {
        if (node.next.value == object) { break; }
        node = node.next;
    }
    
    if (node) {
        LinkNode *nextNode = node.next;
        node.next = nextNode.next;
        if (_tail == nextNode) {
            _tail = node;
        }
        _size--;
    }
}

- (id<MyIterator>)iterator {
    
    return [[LinkIterator alloc] initWithHeadNode:_head];
}



@end
