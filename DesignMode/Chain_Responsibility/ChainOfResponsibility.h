//
//  ChainOfResponsibility.h
//  DesignMode
//
//  Created by jansti on 2017/8/26.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef ChainOfResponsibility_h
#define ChainOfResponsibility_h

/*
 UIResponder
 
 The idea of this pattern is to decouple senders and receivers by giving multiple objects a chance to handle a request. The request gets passed along a chain of objects until one of them handles it.
 The first object in the chain receives the request and either handles it or forwards it to the next candidate on the chain, which does likewise. The object that made the request has no explicit knowledge of who will handle it—we say the request has an implicit receiver.
 each object on the chain shares a common interface for handling requests and for accessing its successor on the chain.
 
 
 
 Benefit
 1. Reduced coupling. The pattern frees an object from knowing which other object handles a request. An object only has to know that a request will be handled "appropriately." Both the receiver and the sender have no explicit knowledge of each other, and an object in the chain doesn't have to know about the chain's structure.
 As a result, Chain of Responsibility can simplify object interconnections. Instead of objects maintaining references to all candidate receivers, they keep a single reference to their successor.
 
 // 设想一下,大话设计模式里面关于责任链的讲解.涨工资这件事,要交给组长,经理,总监,总经理 一层层的审核.但是作为员工,其实并不知道到底谁
 可以决定涨工资这件事.于是,员工就需要知道所有的上司类,一遍遍的询问.那么这样的一个函数怎么写,if else if else if .这样,所有的处理
 逻辑就写到一起了,这样一段代码是非常危险了,任何一点改动都会影响到所有的逻辑.如果要特殊化处理,比如总监不在了,直接从经理到总经理,怎么
 跳过,没有办法,逻辑都写在一个方法里面就没有办法从中拦截.而运用责任链,相当于是把这一坨代码分到了各个子类之中,而且通过对象之间设置下
 一个响应者,相当于可以组合方法的调用.函数的组合是没有办法动态的生成的,但是成员变量,也就是内存空间是可以动态改变的.改变内存空间,导致 
 改变了代码的执行.这能算面向对象的核心思想??
 
 Our examples so far define new links, but often you can use existing object references to form the successor chain. For example, parent references in a part-whole hierarchy can define a part's successor.
 
 
 handleRequest的时候,可以编写一个request类,这个类作为信息的包装.在责任链的不同类,可以运用类型识别,或者动态语言里面的自省方法来进行判断,将原始request类转为自己相关的request类,然后进行处理.
 
 // UIKit
 In addition to handling events, UIKit responders also manage the forwarding of unhandled events to other parts of your app. If a given responder does not handle an event, it forwards that event to the next event in the responder chain. UIKit manages the responder chain dynamically, using predefined rules to determine which object should be next to receive an event. For example, a view forwards events to its superview, and the root view of a hierarchy forwards events to its view controller.
 
 
 
 UIView 的setSuperView 时候,或者没有专门的setSuperView 而是在addSubView,的时候,(就像是Composite模式下,parent这个参数只是在remove,Add的方法里面管理,这样能保证parent的能正确的表示上下级关系),自动调用的setNextRespoonder方法.这样,对于UIView体系来说,superView就是nextResponder了.
 UIResponder 的nextResponser属性是readOnly.
 */


#endif /* ChainOfResponsibility_h */
