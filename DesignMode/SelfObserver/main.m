//
//  main.m
//  SelfObserver
//
//  Created by justin lau on 2017/8/27.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CustomButton.h"

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

        CustomButton *btn = [[CustomButton alloc] init];
        Controller *obj = [[Controller alloc] init];
        [btn addTarget:obj aciton:@"btnClick:" forEvent:1];
        [btn trigger:1];
        
    }
    return 0;
}
