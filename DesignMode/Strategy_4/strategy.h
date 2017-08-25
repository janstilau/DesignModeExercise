//
//  strategy.h
//  DesignMode
//
//  Created by jansti on 2017/8/25.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef strategy_h
#define strategy_h

/*
 策略模式用大白话讲就是：我要做一件事，有很多种不同的做法。然后我就把做这件事的算法，从整个程序的过程中抽象出去。实现解耦。
 所以一个典型的策略模式的本质就是：无状态对象模拟函数指针。策略接口负责提供某种算法服务。
 那么上面就说的很清楚了,策略模式,封装的就是函数指针.其实,每次变化的也都是函数指针,不过我们用面向对象包装住了.
 从这来看,策略模式的super类定义接口,子类实现接口,其实就是定义了一个函数指针.然后每次更换都是更换函数指针.但是,通过面向对象,
 可以在策略类里面,存储状态.如果算法很复杂,那么中间状态的存储是很有必要的.
 策略模式和状态模式一样,都是解构代码.把原本需要if,switch判断的代码,从一个地方,分到了各个子类之中.还需不需要switch呢.有的时候是
 需要的,就是根据switch来赋值策略成员变量.计算的规则则封装在各个类中了.
 
 策略模式和状态模式的句别.
 http://www.ciaoshen.com/java/design%20pattern/2016/06/30/strategyStatePattern.html
 
 
 */


#endif /* strategy_h */
