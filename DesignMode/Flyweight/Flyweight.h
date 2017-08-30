
//
//  Flyweight.h
//  DesignMode
//
//  Created by justin lau on 2017/8/31.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef Flyweight_h
#define Flyweight_h

/*
    享元模式就是tableview的cell缓存池机制.
    享元模式的object有两种状态,一种intrinsic,一种extern,对比到cell.内部状态的数据,就是不会随着数据源改变的数据,
 对于视图类来说,这应该就是视图的组成.而外部数据,则是视图的表现,label表示什么,picture表示什么.
    在UI编辑器里面,自己其实是利用tableview的逻辑实现了一个自定义tableview. cell的生成是用tableview的getcell
 工厂方法获取的,获取之后,根据位置获取图片数据,外部数据,然后cell根据外部数据改变自身的表现.
    当外部数据过多的时候,也可以将外部数据的存储减轻,只存储最重要的数据,外部数据获取的时候,根据primitive数据计算出
 需要的外部数据来,然后赋值过去.
 
 */


#endif /* Flyweight_h */
