//
//  Iterator.h
//  DesignMode
//
//  Created by jansti on 2017/8/26.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef Iterator_h
#define Iterator_h

/*
 之所以要有迭代器这个东西,是为了将迭代的代码从容器的代码中分离.因为迭代可能有很多的规则,当然,最原始的是从头到尾顺次迭代.
 从CPP的类库里面,有着倒序排序.但是可能会有按照规则,比如,一个学生列表里面,返回下一个成绩大于60的学生,这都是不同的规则.
 这些,如果把容器的内部数据结构暴露出来,当然可是实现.但是,就没有一个统一的接口了.比如,链表和数组的遍历方式铁定不一样,
 同样的一套从头到尾遍历的方法,因为所用容器类不同就要专门修改.这样代价太大.
 所以,迭代器就是那个中间层,提供通用的接口,具体的实现,交给各个容器类的编写者去编写相关联的迭代器.也将迭代的功能,从容器类中
 抽取出来了.
 迭代器有两个核心的功能,traverse and acces. 在迭代器内部,要保持一个current的index,保存当前迭代的位置.每一次的++或者next,
 修改这个current,用来表示迭代在按着顺序在一步步的进行.
 
 迭代器和容器类是配对的.迭代器提供了接口,容器类实现具体的迭代器子类.这样的实现,使得不同的容器类可以用一套迭代代码.如果加上泛型,
 nextObject 直接可以返回容器类的装载的数据.
 这也是工厂方法的一个体现.容器类一般都有统一的接口,在容器类的接口里面,有着返回迭代器的接口.这样,容器类的子类返回不同的迭代器子类.
 这是两个平行的继承体系.具体的容器类和具体的迭代器类配合,这也是我们想要的,因为具体的迭代器需要知道具体的容器类的内部数据表示才能
 完成nextobject这样的功能.
 
 因为迭代器,各自保存这自己的current,所以,如果迭代器没有remove这种操作的话.可以同时有着好几个迭代器同时迭代一个容器类.如果有改变
 容器类的操作的时候,迭代器好好设计,如何能在改变数据之后还能正确迭代.
 
 像oc 的array::enumrateWithBlock, 就是一个内部迭代器,因为有了block的存在,可以传入一个函数依次给element实现操作.
 
 现在的各个语言的迭代器已经很完善了.自己写的机会很少.
 
 
 How robustistheiterator?Itcanbedangeroustomodifyanaggregate while you're traversing it. If elements are added or deleted from the aggregate, you might end up accessing an element twice or missing it completely. A simple solution is to copy the aggregate and traverse the copy, but that's too expensive to do in general.
 A robust iterator ensures that insertions and removals won't interfere with traversal, and it does it without copying the aggregate. There are many ways to implement robust iterators. Most rely on registering the iterator with the aggregate. On insertion or removal, the aggregate either adjusts the internal state of iterators it has produced, or it maintains information internally to ensure proper traversal.
 
 // 因为平时都是用begin(),find().所以其实没有考虑过多态返回的是堆迭代器的问题.如果不是堆的,就算返回的是一个引用,又有什么意义呢.
 Using polymorphic iterators in C++. Polymorphic iterators have their cost. They require the iterator object to be allocated dynamically by a factory method. Hence they should be used only when there's a need for polymorphism. Otherwise use concrete iterators, which can be allocated on the stack.
 Polymorphic iterators have another drawback: the client is responsible for deleting them. This is error-prone, because it's easy to forget to free a heap-allocated iterator object when you're finished with it. That's especially likely when there are multiple exit points in an operation. And if an exception is triggered, the iterator object will never be freed.
 The Proxy (207) pattern provides a remedy. We can use a stack-allocated proxy as a stand-in for the real iterator. The proxy deletes the iterator in its destructor. Thus when the proxy goes out of scope, the real iterator will get deallocated along with it. The proxy ensures proper cleanup, even in the face of exceptions. This is an application of the well-known C++ technique "resource allocation is initialization" [ES90]. The Sample Code gives an example.

 
 Iterators may have privileged access. An iterator can be viewed as an extension of the aggregate that created it. The iterator and the aggregate are tightly coupled. We can express this close relationship in C++ by making the iterator a friend of its aggregate. Then you don't need to define aggregate operations whose sole purpose is to let iterators implement traversal efficiently.

*/


#endif /* Iterator_h */
