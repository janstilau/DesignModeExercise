//
//  Decorator.h
//  DesignMode
//
//  Created by jansti on 2017/8/30.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef Decorator_h
#define Decorator_h

/*
    想一下我们在子类复写父类接口的时候一般怎么写.
    dosomething . [super invoke] dosomething .
    一般都这样写,这样就可以在父类的实现的基础上,增加功能. 但是这样写有一个问题就是,代码写在了接口的实现里.
    就好像是一个函数,是一个代码块的集合,写到函数里面,就没有办法去分解这一部分代码了.
    这个时候,引入桥接模式,变成了
    [imp dosomthing] [super invoke] [imp dosomtheing]
    这里不太像带有继承的桥接,仅仅是把新添的功能放到了imp的实现里.这样写有什么好处.imp 可以替换,替换不同的imp 就可以添加不同的功能.
    也就是说,桥接模式的主要作用是代码的分离.
 
    装饰器模式,用的是一种类似的思路. dosomething invokeRefdosomthing dosomething. 自己的内部有一个装饰器和被装饰对象的共同
 父类的引用,这样就可以实现套环.可以用不同的装饰器相互修饰. 装饰器, 修饰装饰器, 修饰装饰器, 修饰原始对象.调用关系是装饰器->修饰装饰
 器->修饰装饰器->原始对象. 这样,原始对象的基础上,我们为他增加了三个功能,而这些功能,没有用继承,而是用组合的方式添加的.客户端可以动态
 控制.
    装饰器模式,把特性的组合,从继承方式中解放了出来.在client代码中,要有他们的组合方式的体现.为什么要这样.如果要用继承,是直接写出类名
 的,这样有什么坏处.坏处在于,类爆炸.为了一个功能的增加,就要产生一个新的类.这样类的数量增加过快,并且, 当功能点需要相互组合的时候,比如,
 有三个功能,就会有六种组合结果,难道要写六个新类,让client去调用吗.
 
    Decorator forwards requests to its Component object. It may optionally perform additional operations
 before and after forwarding the request.
 
    装饰模式,要注意接口的简洁.除了共有的接口,每个类都可以有自己独立的功能,但是,串起来他们的那根线,是通过接口的.接口复杂,会让修饰类要
 实现复杂的功能.这些可能仅仅是存储数据的给接口用,那么这种功能,不应该放到接口里面.
 
 Changing the skin of an object versus changing its guts. We can think of a decorator as a skin over an object that changes its behavior. An alternative is to change the object's guts. The Strategy (315) pattern is a good example of a pattern for changing the guts.
 Strategies are a better choice in situations where the Component class is intrinsically heavyweight, thereby making the Decorator pattern too costly to apply. In the Strategy pattern, the component forwards some of its behavior to a separate strategy object. The Strategy pattern lets us alter or extend the component's functionality by replacing the strategy object.
 For example, we can support different border styles by having the component defer border-drawing to a separate Border object. The Border object is a Strategy object that encapsulates a border-drawing strategy. By extending the number of strategies from just one to an open-ended list, we achieve the same effect as nesting decorators recursively .
 In MacApp 3.0 [App89] and Bedrock [Sym93a], for example, graphical components (called "views") maintain a list of "adorner" objects that can attach additional adornments like borders to a view component. If a view has any adorners attached, then it gives them a chance to draw additional embellishments. MacApp and Bedrock must use this approach because the View class is heavyweight. It would be too expensive to use a full-fledged View just to add a border.
 Since the Decorator pattern only changes a component from the outside, the component doesn't have to know anything about its decorators; that is, the decorators are transparent to the component:
 With strategies, the component itself knows about possible extensions. So it has to reference and maintain the corresponding strategies:
 The Strategy-based approach might require modifying the component to accommodate new extensions. On the other hand, a strategy can have its own specialized interface, whereas a decorator's interface must conform to the component's. A strategy for rendering a border, for example, need only define the interface for rendering a border (DrawBorder, GetWidth, etc.), which means that the strategy can be lightweight even if the Component class is heavyweight.
 MacApp and Bedrock use this approach for more than just adorning views. They also use it to augment the event-handling behavior of objects. In both systems, a view maintains a list of "behavior" objects that can modify and intercept events. The view gives each of the registered behavior objects a chance to handle the event before nonregistered behaviors, effectively overriding them.
 
 
 
 */


#endif /* Decorator_h */
