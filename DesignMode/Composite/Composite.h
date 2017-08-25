
//
//  Composite.h
//  DesignMode
//
//  Created by jansti on 2017/8/25.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef Composite_h
#define Composite_h


/*
 组合模式,将对象组合成树形结构以表示 "部分整体"的层次结构.组合模式使得用户对单个对象和组合对象的使用具有一致性.
 无论是UIView 还是 Logicelement, 都是组合模式. 我们可以看到,作为Component的公共父类这一类,其实是很庞大的.
 各个子类实现了自己各自的功能,但是公众的子对象管理,一些功能的行为的展示,都是在父类里面写到的.通用方法写在父类,子类
 就可以无差别的被对待.
 1.在component里面,添加parent的引用,可能方便遍历,例如,UIView的响应者的传递,logicelement的寻找顶层trigger都是用到了
 parent这一成员变量.在之前的代码里面,也是多次运用了parent这一属性.parent这一变量,可以通过遍历child列表得到.但是,专门维护
 parent,在之后的代码中会方便很多.parent的改变,只在addChild 和 remove 的操作里面,也能确保这个成员变量的值的准确性.
 2.addChild这一方法,该不该专门写在composite类里面.现在的应用看来,不应该.在UIView体系下面,任何的视图都可以添加子视图.
 因为UIView的实现,UILabel看起来是很primitive,但是实际上它还是被许多许多的子控件构建出来的.UILabel在Apple的设计里面,
 是可以添加子控件的.而在LogicElement里面,aciton虽然数量多,但是类的种类来看,需要管理child的类型数量占了绝大部分.
 如果想要只在composite里面管理child,可以component里面写一个getComposite的接口,primitive返回null,只有composite返回
 this,这样,算是一个类型识别的表示.
 
 
 
 
 */


#endif /* Composite_h */
