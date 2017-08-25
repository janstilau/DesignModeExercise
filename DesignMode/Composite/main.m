//
//  main.m
//  Composite
//
//  Created by justin lau on 2017/8/25.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LogicElement.h"

LogicElement *makeElement(){
    return [[LogicElement alloc] init];
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        LogicElement *log_1 = makeElement();
        LogicElement *log_2 = makeElement();
        LogicElement *log_3 = makeElement();
        LogicElement *log_4 = makeElement();
        LogicElement *log_5 = makeElement();
        
        [log_1 addChild:log_5];
        [log_5 addChild:log_2];
        [log_1 addChild:log_3];
        NSArray<LogicElement *> *array = @[log_1,log_2,log_3,log_4,log_5];
        NSLog(@"%@",array);
        
        NSArray<LogicElement *> *filterArray = [LogicElement cleanSelection:array];
        NSLog(@"%@", filterArray);
        
        
        
    }
    return 0;
}
