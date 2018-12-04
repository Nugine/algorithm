# HDU 1395

## 题目：[2^x mod n = 1](http://acm.hdu.edu.cn/showproblem.php?pid=1395)

## 解法1： 暴力

x 从 1 取起，挨个算一下，第一个满足要求的 x 就是 ans.

为了避免溢出，需要用乘法取模。

    (a * b) % m = ((a % m) * (b % m)) % m

## 解法2： 欧拉定理

概念： **阶**

设 n > 1 且 a, n 互质，则有最小的正整数 t 使得 a ^ t % n = 1.
此时称 t 为 a 对模 n 的阶，记为 Ord(a).

概念： **原根**

由欧拉定理可知 Ord(a) <= Phi(n).
当 Ord(a) = Phi(n) 时，称 a 是模 n 意义下 n 的一个原根.

因为要有解， n 必须是大于1的奇数，所以 (2, n) = 1.

可得 ans = Ord(a), ans 的上界为 Phi(n).

因为 

    a ^ Ord(a) % m = 1
    a ^ Phi(m) % m = 1
    Ord(a) <= Phi(m)

所以

    Ord(a) | Phi(m)

所以 ans 是 Phi(n) 的因子.

先计算 Phi(n)，然后枚举因子，最小的满足条件的因子就是 ans.

## 代码

解法1： [mod.1.cpp](mod.1.cpp)

解法2： [mod.2.cpp](mod.2.cpp)
