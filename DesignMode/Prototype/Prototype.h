//
//  Prototype.h
//  DesignMode
//
//  Created by jansti on 2017/9/1.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef Prototype_h
#define Prototype_h

/*
 陈硕
 Prototype 的意义在于，你拿到一个 Base* ，它指向某个 Derived 对象，你想克隆出 Derived 对象，但代码中不写出 Derived 的具体类型，因为有很多派生类，这种情况下你用构造函数是搞不定的，type-switch 是 bad smells 。
 另外，这里考虑 virtual 的性能损失是主次不分，构造对象需要分配内存，这开销比一次虚函数调用大多了。
 Prorobuf Message 就采用了 prototype 模式，你可以参考一下。
 
 */


#endif /* Prototype_h */
