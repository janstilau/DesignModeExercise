//
//  Factory.h
//  DesignMode
//
//  Created by jansti on 2017/8/31.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef Factory_h
#define Factory_h



/*
 Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.
 • a class can't anticipate the class of objects it must create.
 • a class wants its subclasses to specify the objects it creates.
 • classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate.
    视频和大话那本书里,给的例子都是有一个产品A,然后就有一个FactoryA,这样想要A的时候,直接调用FactoryA的方法的到A就可以了.
 不过这样写感觉很没有意义,工厂方法仅仅是生产商品而已.
    在gof的书里面,工厂方法不是这样用的.比如,UIView的可能需要有个操作者的角色,记录鼠标的移动,点击,状态,根据这些状态来调整UIView的
 位置,大小,那么这个时候,不同的UIView的操作者可能具体的实现是不一样的,但是他们的接口是一样的.在UIView所在panel的事件处理里面,就可
 以通过接口编程,操作抽象的操作者.而实际的操作者,是不同的UIView返回不同的和自己UIView相关的操作者对象.这样,就将实现和接口进行了分离
 ,不同的UIView有着不同的操作行为,但是它们的接口,却可以统一的写在panel里面.
    
 
 */

#endif /* Factory_h */
