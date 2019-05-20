# week-1

## 栈

[HDU-4699](http://acm.hdu.edu.cn/showproblem.php?pid=4699)

对顶栈，维护性质

[HDU-1237](http://acm.hdu.edu.cn/showproblem.php?pid=1237)

中缀表达式转换到后缀表达式，利用栈求值

[HDU-2127](http://acm.hdu.edu.cn/showproblem.php?pid=2127)

中缀表达式转换到前缀表达式，利用栈求值

[POJ-2559](http://poj.org/problem?id=2559)

单调栈

## 队列

[BZOJ-2457](https://www.lydsy.com/JudgeOnline/problem.php?id=2457)

队列 ×，贪心 √

按（数值，序号）排序，将相同的数值缩成点，得到一些具有头和尾的、可以调换方向的序列。
将这些序列尽可能组成先降后升的大序列，这些大序列就是“双端队列”的内部组成，最后统计有多少个这样的大序列。

[洛谷 P1886](https://www.luogu.org/problemnew/show/P1886)

单调队列

维护一个单调递增队列，用后来的小值把前面的大值顶出去，加入队尾，队首离开窗口的数值也弹出去。
这样的队列中保存的就是当前有效区间内的单调递增数值，队首就是当前窗口内的最小值。最大值只要反过来就行了。

[洛谷 P2032](https://www.luogu.org/problemnew/show/P2032)

单调队列

洛谷 P1886 的弱化版本，算法一样的。

[洛谷 P1725](https://www.luogu.org/problemnew/show/P1725)

动态规划，单调队列优化

    for i from n to 0
    dp[i]=a[i]+max(dp[k] for k in [i+l, i+r]), i+l <= n
    dp[i]=a[i]+0, i+l >  n

`dp[i]` := 从第 i 个位置到对岸的最大冰冻指数
倒过来dp，最后的`dp[0]`就是`ans`。

转移方程中有个`O(n)`的计算式，显然需要优化这一部分。

利用类似 洛谷 P2032 的滑动窗口单调队列，可以优化到`O(1)`。

最终时间复杂度`O(n)`

[POJ-1742](http://poj.org/problem?id=1742)

动态规划

TODO: 补上解析

<del>抄的代码，没看懂</del>

## 莫队

[SPOJ D-query](https://www.spoj.com/problems/DQUERY/en/)

莫队

神奇莫队第一课。因为 `Ai` 属于区间 `[1, 1e6]`，可以`O(1)`映射到个数，所以区间`[l,r]`可以直接转移到邻近区间，满足莫队所需性质。莫队标准`sqrt(n)`分块排序，降低转移次数，完成所有询问，将答案填入询问的对应位置，最后依次输出。

[BZOJ-2038](https://www.lydsy.com/JudgeOnline/problem.php?id=2038)

莫队，组合数学

<http://foreseeable97.logdown.com/posts/158522-233333>
