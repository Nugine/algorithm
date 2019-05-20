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