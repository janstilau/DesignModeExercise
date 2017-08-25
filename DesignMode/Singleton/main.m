//
//  main.m
//  Singleton
//
//  Created by jansti on 2017/8/25.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PhotoManager : NSObject

+ (instancetype)instance;

- (void)operation;

@end

@implementation PhotoManager


+ (instancetype)instance {
    
    return [[PhotoManager alloc] init];
}

//+ (instancetype)instance {
//    if (!_instance) {
//        @synchronized (_instance) {
//            if (!_instance) {
//                _instance = [[PhotoManager alloc] init];
//            }
//        }
//    }
//    return _instance;
//}

+ (instancetype)allocWithZone:(struct _NSZone *)zone {
    
    static PhotoManager *_instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [super allocWithZone:zone];
    });
    return _instance;
}

- (void)operation {
    NSLog(@"%@", self);
}

@end




int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"%@", [PhotoManager instance]);
        NSLog(@"%@", [[PhotoManager alloc] init]);
        NSLog(@"%@", [[PhotoManager alloc] init]);
        NSLog(@"%@", [[PhotoManager alloc] init]);
    }
    return 0;
}
