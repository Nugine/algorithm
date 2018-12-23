# HDU 1207

## 题目：[汉诺塔II](http://acm.hdu.edu.cn/showproblem.php?pid=1207)

## 公式: [OEIS-A007664](http://oeis.org/A007664)

    A007664(n) = sum(2 ^ A003056(i), i = 0..n-1)

    A003056(n) = floor((sqrt(1 + 8 * n) - 1) / 2)


记 A(n) = A007664(n), B(n) = A003056(n).

    A(n) = A(n-1) + 2 ^ B(n-1)
    B(n-1) = floor((sqrt(1 + 8 * (n-1)) - 1) / 2)

使用下标 i 转写.

    A[i+1] = A[i] + 2 ^ floor((sqrt(1 + 8 * i) - 1) / 2)

快速幂+递推, 即得解.

由于题目数据范围较小, 不用取模, 可预打表.

这里使用惰性递推, 当 A(n) 不在已有的数据内时, 递推计算出 A(n)时就返回.

## 代码

[hanoi4.cpp](hanoi4.cpp)
