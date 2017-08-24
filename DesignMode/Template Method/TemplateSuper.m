//
//  TemplateSuper.m
//  DesignMode
//
//  Created by jansti on 2017/8/24.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import "TemplateSuper.h"

@implementation TemplateSuper

- (void)operation {
    NSLog(@"prepare");
    [self subOperation_1];
    NSLog(@"other operation");
    [self subOperation_2];
    [self subOperation_3];
    NSLog(@"end");
}

- (void)subOperation_1 {
    
    NSLog(@"super operation _ 1");
}

- (void)subOperation_2 {
    
    NSLog(@"super operation _ 2");
}

- (void)subOperation_3 {
    
    NSLog(@"super operation _ 3");
}

@end
