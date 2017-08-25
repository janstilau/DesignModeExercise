//
//  LogicElement.m
//  DesignMode
//
//  Created by jansti on 2017/8/25.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import "LogicElement.h"

@interface LogicElement ()

@property (nonatomic, strong) NSMutableArray *children;

@end

@implementation LogicElement

- (void)removeChild:(LogicElement *)child {
    
    NSUInteger index = [_children indexOfObject:child];
    if (index == NSNotFound) {
        return;
    }
    child.parent = NULL;
    [_children removeObjectAtIndex:index];
}

- (int)indexOfChild:(LogicElement *)child {
    
    return (int)[_children indexOfObject:child];
}

- (void)addChild:(LogicElement *)child {
    
    [self insertChildInIndex:-1 child:child];
}

- (void)insertChildInIndex:(int)index child:(LogicElement *)child {
    
    NSAssert(child, @"child is empty");
    if (!child) {
        return;
    }
    
    NSAssert(child != self, @"child is equal to this");
    
    if (index < 0) {
        [_children addObject:child];
    } else {
        [_children insertObject:child atIndex:index > _children.count ? _children.count : index];
    }
    child.parent = self;
}

- (bool)isParentOrSuperParent:(LogicElement *)element {
    
    LogicElement *parent = element.parent;
    if (!parent) {
        return false;
    }
    
    for(; parent; parent = parent.parent) {
        if (parent == self) {
            return true;
        }
    }
    return false;
}

- (bool)traverseChildren:(bool (^)(LogicElement *)) func {
    
    if (func(self)) {
        return true;
    }
    for (LogicElement *child in _children) {
        if ( [child traverseChildren:func]) {
            return true;
        }
    }
    return false;
}

- (bool)traverseChildrenReversely:(bool (^)(LogicElement *)) func {
    
    NSEnumerator<LogicElement *> *enumerator = [_children reverseObjectEnumerator];
    LogicElement *current = enumerator.nextObject;
    for ( ; current ;  current = enumerator.nextObject) {
        if ([current traverseChildren:func]) {
            return true;
        }
    }
    return false;
}

+ (NSArray<LogicElement *> *)cleanSelection: (NSArray<LogicElement *> *) originSelection {
    
    if (originSelection.count == 0 || originSelection.count == 1) { return originSelection; }
    
    NSMutableArray<LogicElement *> *selection = [originSelection mutableCopy];
    for (int i = 0; i < selection.count; i++) {
        LogicElement *ele = [selection objectAtIndex:i];
        for (int j = 0; j < selection.count; j++) {
            if (i == j) { continue; }
            LogicElement *eleToCheck = [selection objectAtIndex:j];
            if ([eleToCheck isParentOrSuperParent:ele]) {
                [selection removeObjectAtIndex:i];
                i--;
                break;
            }
        }
    }
    return [selection copy];
}

@end
