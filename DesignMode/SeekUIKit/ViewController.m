//
//  ViewController.m
//  SeekUIKit
//
//  Created by jansti on 2017/8/26.
//  Copyright © 2017年 jansti. All rights reserved.
//

#import "ViewController.h"



@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(catchNotifi:) name:@"lalala" object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(catchNotifi_2:) name:@"lalala" object:self];
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"lalala" object:self];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"1" object:nil];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"2" object:nil userInfo:nil];
    
    UIButton *btn;
    [btn addTarget:self action:@selector(hehe) forControlEvents:UIControlEventAllEvents];
    
    
    
}
- (IBAction)click:(UIButton *)sender {
    
    
}

- (void)catchNotifi:(NSNotification *)noti {
    NSLog(@"%@ _catch_1", noti);
    
    NSString *str = [NSString stringWithFormat:@"%p",self];
    NSLog(@"%@%@", str, noti.name);
}

- (void)catchNotifi_2:(NSNotification *)noti {
    NSLog(@"%@ _catch_2", noti);
}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"lalala" object:self];
}


@end
