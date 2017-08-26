//
//  main.m
//  Iterator
//
//  Created by jansti on 2017/8/26.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ArrayList.h"
#import "LinkList.h"

NSObject *make() {
    
    return [[NSObject alloc] init];
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        id<Container> array = [[LinkList alloc] init];
        id one = make();
        id two = make();
        [array addObject:one];
        [array addObject:two];
        [array addObject:one];
//        NSLog(@"%@",@(array.size));
//        [array removeobject:one];
//        NSLog(@"%@",@(array.size));
//        [array removeobject:one];
//        NSLog(@"%@",@(array.size));
//        [array removeobject:one];
//        NSLog(@"%@",@(array.size));
        
        
        id<MyIterator> it = [array iterator];
        while (it.hasNext) {
            id obj = it.nextObject;
            NSLog(@"%@", obj);
        }
        
    }
    return 0;
}
