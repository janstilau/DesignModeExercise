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
 
 
 https://developer.apple.com/library/content/documentation/General/Conceptual/CocoaEncyclopedia/Model-View-Controller/Model-View-Controller.html#//apple_ref/doc/uid/TP40010810-CH14-SW1
 Model-View-Controller is a design pattern that is composed of several more basic design patterns. These basic patterns work together to define the functional separation and paths of communication that are characteristic of an MVC application. However, the traditional notion of MVC assigns a set of basic patterns different from those that Cocoa assigns. The difference primarily lies in the roles given to the controller and view objects of an application.
 
 In the original (Smalltalk) conception, MVC is made up of the Composite, Strategy, and Observer patterns.
 
 Composite—The view objects in an application are actually a composite of nested views that work together in a coordinated fashion (that is, the view hierarchy). These display components range from a window to compound views, such as a table view, to individual views, such as buttons. User input and display can take place at any level of the composite structure.
 Strategy—A controller object implements the strategy for one or more view objects. The view object confines itself to maintaining its visual aspects, and it delegates to the controller all decisions about the application-specific meaning of the interface behavior.
 Observer—A model object keeps interested objects in an application—usually view objects—advised of changes in its state.
 The traditional way the Composite, Strategy, and Observer patterns work together is depicted by Figure 7-1: The user manipulates a view at some level of the composite structure and, as a result, an event is generated. A controller object receives the event and interprets it in an application-specific way—that is, it applies a strategy. This strategy can be to request (via message) a model object to change its state or to request a view object (at some level of the composite structure) to change its behavior or appearance. The model object, in turn, notifies all objects who have registered as observers when its state changes; if the observer is a view object, it may update its appearance accordingly.
 
 Figure 7-1  Traditional version of MVC as a compound pattern
 Traditional version of MVC as a compound pattern
 The Cocoa version of MVC as a compound pattern has some similarities to the traditional version, and in fact it is quite possible to construct a working application based on the diagram in Figure 7-1. By using the bindings technology, you can easily create a Cocoa MVC application whose views directly observe model objects to receive notifications of state changes. However, there is a theoretical problem with this design. View objects and model objects should be the most reusable objects in an application. View objects represent the "look and feel" of an operating system and the applications that system supports; consistency in appearance and behavior is essential, and that requires highly reusable objects. Model objects by definition encapsulate the data associated with a problem domain and perform operations on that data. Design-wise, it's best to keep model and view objects separate from each other, because that enhances their reusability.
 
 In most Cocoa applications, notifications of state changes in model objects are communicated to view objects through controller objects. Figure 7-2 shows this different configuration, which appears much cleaner despite the involvement of two more basic design patterns.
 
 Figure 7-2  Cocoa version of MVC as a compound design pattern
 Cocoa version of MVC as compound design pattern
 The controller object in this compound design pattern incorporates the Mediator pattern as well as the Strategy pattern; it mediates the flow of data between model and view objects in both directions. Changes in model state are communicated to view objects through the controller objects of an application. In addition, view objects incorporate the Command pattern through their implementation of the target-action mechanism.
 
 Note: The target-action mechanism, which enables view objects to communicate user input and choices, can be implemented in both coordinating and mediating controller objects. However, the design of the mechanism differs in each controller type. For coordinating controllers, you connect the view object to its target (the controller object) in Interface Builder and specify an action selector that must conform to a certain signature. Coordinating controllers, by virtue of being delegates of windows and the global application object, can also be in the responder chain. The bindings mechanism used by mediating controllers also connects view objects to targets and allows action signatures with a variable number of parameters of arbitrary types. Mediating controllers, however, aren’t in the responder chain.
 There are practical reasons as well as theoretical ones for the revised compound design pattern depicted in Figure 7-2, especially when it comes to the Mediator design pattern. Mediating controllers derive from concrete subclasses of NSController, and these classes, besides implementing the Mediator pattern, offer many features that applications should take advantage of, such as the management of selections and placeholder values. And if you opt not to use the bindings technology, your view object could use a mechanism such as the Cocoa notification center to receive notifications from a model object. But this would require you to create a custom view subclass to add the knowledge of the notifications posted by the model object.
 
 In a well-designed Cocoa MVC application, coordinating controller objects often own mediating controllers, which are archived in nib files. Figure 7-3 shows the relationships between the two types of controller objects.
 
 
 传统的mvc模式,view的事件处理交给controller,然后在controller里面更改view,model的数据.在model的数据被更改了之后,model会发送
 自己被更改的消息,它的监听者监听到这个消息之后,或者根据消息的信息更新自己,或者再去调用model的方法更新自己.也就是说,其实movel和view
 之间有耦合.view将自己注册给model,才能在model发生改变的时候,进行更新.
 在cocoa的mvc模式下,controller的作用被凸显出来.view的事件交给controller进行处理,controller更改model 数据,同时,在model的
 数据被更改的时候,model将自己的状态更改,交由controller,也就是说,model和view之间没有联系.一切都交由controller进行
调节.controller从事件的处理者,增加了数据的协调者的功能.
 所以说,cocoa的controller就是mediater模式.controller保持着数据的更改操作,保持着数据更改其他视图的更新操作,知道model数据,各个
 view数据,知道他们之间的联系.这样,controller其实是很难复用的代码,但是它将view和model的复用抽取了出来.
    
 
 
 */

#endif /* Factory_h */
