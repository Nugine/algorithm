# week-2

## 并查集

[POJ-2492](http://poj.org/problem?id=2492)

种类并查集

结点中加一个`diff`字段，表示当前结点与根的种类是否相同。

初始化`root`为0，表示结点的根是自己，`diff`为0，表示结点与自己的种类相同。

压缩路径时，会得到结点与原根、原根与总根的种类关系，异或得到结点与总根的种类关系。

对于每对应该被标记为种类不同的结点`x1, x2`，取根`r1, r2`。

如果根不同，则计算根之间的种类关系，标记、合并。想象一个正方形，其中三条边已知，计算第四条边，只要三条边取异或就行了。

如果根相同，则计算结点之间的种类关系（想象一个三角形），如果种类相同，说明冲突，如果不同，说明不冲突。

[POJ-1182](http://poj.org/problem?id=1182)

带权并查集

结点中加`rank`字段，表示当前结点与根的逻辑距离。

初始化`root`为0，表示结点的根是自己，`rank`为0，表示结点与自己的逻辑距离为0。

食物链形成了长度为3的环，因此逻辑距离`rank`表示当前结点在环上与根的距离，取值范围`[0, 1, 2]`。

压缩路径时，把距离加起来模3。合并集合时，如果是同类，偏移量为0，如果是捕食关系，偏移量为1，即被合并的结点要比合并到的结点在环上右移一位。

方程 `0 + x.rank + offset ≡ ry.rank + y.rank (%3)`

TODO: [BZOJ-3674](https://www.lydsy.com/JudgeOnline/problem.php?id=3674)

可持久化并查集

<del>可持久化要练好些题呢，我还不会</del>

<http://hzwer.com/3997.html>

<https://blog.csdn.net/qq_42112677/article/details/81099959>

<https://blog.csdn.net/Diogenes_/article/details/80392170>

## 跳舞链

TODO: <https://blog.csdn.net/whereisherofrom/article/details/79220897>

<del>看起来过于牛逼，于是列为todo</del>

## 莫队

[洛谷 P2709](https://www.luogu.org/problemnew/show/P2709)

莫队

标准莫队，维护一个`cnt`数组，保存区间内各数字的出现个数，`add`和`remove`函数计算一下`delta`，加到`ans`上，就这么多。

[洛谷 P1903](https://www.luogu.org/problemnew/show/P1903)，[BZOJ-2120](https://www.lydsy.com/JudgeOnline/problem.php?id=2120)

带修莫队

<https://www.cnblogs.com/ouuan/p/MoDuiTutorial.html>

在标准莫队的基础上加一维时间轴，如果当前点与查询点在时间轴上有距离，则要不断执行/撤销修改操作，直到到达修改完成后的时间点。

[BZOJ-4241](https://www.lydsy.com/JudgeOnline/problem.php?id=4241)

回滚莫队

<https://blog.csdn.net/qq_33330876/article/details/73522230>
