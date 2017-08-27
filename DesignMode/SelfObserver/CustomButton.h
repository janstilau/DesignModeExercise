//
//  CustomButton.h
//  DesignMode
//
//  Created by justin lau on 2017/8/27.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CustomButton : NSObject

@property (nonatomic, strong) NSMapTable *cache;

- (void)addTarget:(id)target aciton:(NSString *)action forEvent:(int)event;
- (void)trigger:(int) evnt;

@end
