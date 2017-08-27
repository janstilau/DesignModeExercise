//
//  Observer.h
//  DesignMode
//
//  Created by jansti on 2017/8/26.
//  Copyright © 2017年 jansti. All rights reserved.
//

#ifndef Observer_h
#define Observer_h

/*

 
 Target action 和 notification 其实都没有涉及到传值的问题. notification 是直接传过来了一个object,但是那是一个void*,
 而targetAction传过来的responder,这个里面其实没有信息的.所有的操作,都在controller里面.
 传统的MVC总是在数据改变了只有通过通知传递给observer,我认为是因为桌面软件的界面过于庞大,而手机端的界面其实没有那么复杂.因为
 屏幕的限制,手机端的业务,一个页面几乎就是一个新的功能.不会存在着一个数据改变需要界面上多处小控件进行更新的情况.这样,把所有的操作
 通过controller来管理.如果在数据类里面,发很多的通知,不好管理.
 在BIG4的observer模式里面,subject要维护一个获取自身数据的接口.也就是,观察者要知道发布者到底是谁,向谁去询问.这在iOS里面,void *
 传递过来了.但是因为是void*,一点意义没有.
 ConcreteSubject notifies its observers whenever a change occurs that could make its observers' state inconsistent with its own.
 • After being informed of a change in the concrete subject, a ConcreteObserver object may query the subject for information. ConcreteObserver uses this information to reconcile its state with that of the subject.
 
 NotificationCenter
 Support for broadcast communication. Unlike an ordinary request, the notification that a subject sends needn't specify its receiver. The notification is broadcast automatically to all interested objects that subscribed to it. The subject doesn't care how many interested objects exist; its only responsibility is to notify its observers. This gives you the freedom to add and remove observers at any time. It's up to the observer to handle or ignore a notification.
 
 iOS里面,通知是通过固定的键值取到的.而这是程序的编写者事先就定好的.于是,我们自己编写一个通知,也要这么做.
 This problem is aggravated by the fact that the simple update protocol provides no details on what changed in the subject. Without additional protocol to help observers discover what changed, they may be forced to work hard to deduce the changes.

 
 // btn 的observer 实现了.简单说一下notificationCenter的思路
  NSDictionary<NSString, NSArray<NSDictionary<NSString *, id>>> 可以用来做数据的存储.因为好像center里面会有强引用
 这里也就用Dictionary了.
 NSString的键,是在addObserver:action:forNotification:obj 的时候,observer,action,构成类面的作为值的
 dictionary,提前定义常量key,MyNotificationObserver,MyNotificationAction用为key.而后面的
 NotificationName 和 NotificationPoster 可以用 name 和 poter的地址构建出一个作为外面大diction的key.如果
 没有object,就单用NotificaitonName做eky
 这样,在postNotificaiton的时候,就可以构建出一个唯一的key来了.然后这个唯一的key对应的array,里面存储了observer和aciton的信息.如果没有obj,就单用notificaitonName 做key.实验证明了,一个observer,添加同一个notificaitonName, 一个指定了obj,一个没有指定,发送一次notificaiotn,observer会调用两次方法.
 
 
 */

#endif /* Observer_h */
