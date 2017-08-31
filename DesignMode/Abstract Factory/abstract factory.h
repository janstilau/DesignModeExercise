//
//  abstract factory.h
//  DesignMode
//
//  Created by jansti on 2017/8/31.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef abstract_factory_h
#define abstract_factory_h

/*
    Provide an interface for creating families of related or dependent objects without specifying their
concrete classes.
    IFactory 是一个抽象工厂接口,里面应该包含所有的产品创建的抽象方法.而具体的方法,要实现这些方法.抽象工厂里面返回的是抽象产品,
 具体工厂里面返回的是具体的产品.工厂类有一个集成体系,产品类有一个集成体系.他们是互相独立的.抽象工程方法的作用,就是将这些产品进行整合.
    抽象工厂类:  1 生产抽象A     2 生产抽象B                 抽象A                 抽象B
    具体工厂类1: 1 生产具体A_1   2 生产具体B_1               具体A_1               具体B_1
    具体工厂类2: 1 生产具体A_2   2 生产具体B_2               具体B_2               具体B_2
 1  替换整体产品系统容易
 2  具体的创建实例的过程和客户端分离,客户端通过抽象接口操作实例.具体的类名仅仅出现在具体工厂里.
 3  可以将工厂类的继承体系去除,在工厂类里面用简单工厂代替.也就是在简单通常里面,通过switch判断,来创建不同的产品.
 4  缺点,增加产品代价比较昂贵.
 
    简单工厂方法.通过参数值来确定具体创建什么产品.创建的产品还是接口产品,在UIButton buttonWithType里面用到的就是简单工厂.在没有
 系列产品的这种需求的时候,一般简单工程,配以enum枚举值,就能实现一般情况下生产产品的需要.
    因为工厂方法,最重要的是,产品的生产过程和客户端分离.用生产出的接口产品编程.
 
    目前的工作经历,没有用过抽象工厂方法.因为抽象工厂方法,更多的是为了维护系列产品.
 */

#endif /* abstract_factory_h */
