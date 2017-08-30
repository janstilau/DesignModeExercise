//
//  Bridge.h
//  DesignMode
//
//  Created by jansti on 2017/8/30.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef Bridge_h
#define Bridge_h

/*
    合成聚合复用原则: 尽量使用合成/聚合,尽量不要使用类继承.
    聚合表示一种弱的拥有关系,体现的是A对象可以包含B,但是B不是A对象的一部分.合成则是一种强的拥有关系,体现了严格的部分和整体的关系,部
 分和整体的声明周期是一样的.优先使用对象的合成聚合有助于你保持每个类被封装,并且被击中在单个任务中,这样类和类继承层次会保持较小的规模,
 并且不太可能增长为不可控制的庞然大物.
 
    继承实现多态的结果是,接口和实现是静态绑定在一起的.在运行时无法改变,而且,想要增加新功能,就要将代码写在类里面,这样,这个类的代码就
 越来越大.因为,子类虽然只是增加一个接口,或者重写了一个接口,但是,和这个子类的代码,确实从根类就开始的.根类到父类的一点改变就要影响全部
 的子类.这样,当一个功能不满足需求的时候,更改它就要影响所有的子类用户,代价太大.
 
    桥接模式,就是为了接口和实现的分离.具体的实现,交给实现对象处理.其实这种处理方式,和状态,策略,代理,适配器是一样的.不过他们的目的不
 同,桥接,连接的是实现和接口.接口有着继承体系,实现相对于的也有一套继承体系.他们是平行关系.
    这样做,首先是将接口和实现进行了分离,实现不写在接口类里面,也能通过更改实现对象,动态更改接口的实现.
    再者,接口和实现的平行继承体系意味着,父类接口用父类实现,子类接口用子类实现,运用工厂方法就可以维护这样的一个稳定的关系.
    因为实现的变化封装到了接口类的内部,客户在编写的时候,面向接口使用就可以了,客户端代码也可以稳定.
 
 
    接口类,利用实现类的接口进行编程.实现类给出的primitive接口,是一些底层操作,接口类利用这些底层操作,组合出高级操作.接口类不用和
 实现类拥有同样的接口.
 
 
    我觉得,桥接更多的意义在于,接口和实现的分离.在之前的代码中,也运用很多的桥接模式,不过,业务代码相对没有那么复杂,所以没有继承的层次
 展示,于是,仅仅是代码的分离.应该说,桥接模式,是状态模式,策略模式的基础.也是这种用组合代替继承的基础.
 
 */


#endif /* Bridge_h */