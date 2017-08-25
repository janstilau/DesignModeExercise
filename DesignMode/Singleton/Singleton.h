
//
//  Singleton.h
//  DesignMode
//
//  Created by jansti on 2017/8/25.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef Singleton_h
#define Singleton_h

/*
 单例模式
 
 想要有一个类的对象,可以被公共的使用,可以使用什么办法呢.全局变量.
 如果想要这个对象只有一个呢,全局变量不可以.
 1.类,自身内部管理一个私有对象.可以通过类方法来获取这个对象.在cpp里面,将构造方法进行私有化,防止通过构造方法进行实例化.
    在OC里面,重写allocWithZone方法.
 2.单例对象,就是实例对象.所以对象内部有着很多的成员变量可以记录状态.
 3.多线程的情况下.可以运用synchronize双重锁定.oc有dispatch_once.
 
 
 */


#endif /* Singleton_h */
