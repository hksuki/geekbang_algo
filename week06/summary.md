# 在做有关动态规划的习题时我们怎样去分析（来自宫水三叶）

[【动态规划/总结必看】从一道入门题与你分享关于 DP 的分析技巧](https://mp.weixin.qq.com/s/G_KYdjrhQQO43-t0Jw8iBA)

## 如何确定一个题目是否能够使用动态规划进行求解

这个要从**有无后效性**进行入手分析。
如果对于某个状态，我们可以只关注状态的值，而不需要关注状态是如何转移过来的话，这就是一个无后效性的问题，可以考虑使用DP解决。

举个简单的例子就是：围棋具有无后向性。比如我们下围棋，现在有个局面，可能是随机摆成的，也可能是认真下成这样的，但是这不会影响我们下一步应该下的位置。也就是说历史信息不会影响我们以后的决策，当前的局面就是一个里程碑，就是对历史的总结，也是唯一影响未来的东西。

作者：匿名用户
链接：https://www.zhihu.com/question/43361359/answer/95544830
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

## 我们是如何确定本题的状态定义的？

DP状态的定义很大程度上是靠经验去猜的。
虽然大多数情况都是猜的，但也不是毫无规律，相当一部分题目的状态定义是与**结尾**和**答案**有所关联的。

## 我们是如何定义状态转移方程的？

通常来说，如果状态定义正确，**状态转移方程**就是对**最后一步的分情况讨论**。如果我们有一个对的**状态定义**的话，基本上**状态转移方程**就是呼之欲出。因此一定程度上，**状态转移方程可以反过来验证我们状态定义猜的是否正确**。如果猜了一个状态定义，然后发现无法涵盖所有情况（不漏）的状态转移方程，多半是**状态定义猜错了，赶紧换个思路，而不是去死磕状态转移方程**。

## 对状态转移的要求是什么

状态转移是要做到**不漏**还是**不重不漏**取决于问题本身：
- 如果是求最值问题，只需要确保**不漏**即可
- 如果是求方案数的话，要确保**不重不漏**

## 如何分析动态规划的时间复杂度

对动态规划的复杂度/计算量分析，有多少个状态就有多少复杂度/计算量