# 组合数取模 C(n, m) % p

## 计算式

    C(n, m) = n! / (m! * (n - m)!)

## 解法1：暴力计算 + gcd 约分

此处略去

## 解法2：乘法逆元

当 (a, p) = 1 且 a * b % p = 1 时，称 b 为 a % p 的逆元。

当 b % p 的逆元为 c 时，可得

      (a / b) % p
    = ((a / b) % p) * ((b * c) % p)
    = (a * c) % p

计算式

      C(n, m) % p
    = n! / (m! * (n - m)!) % p
    = n! * inv(m! % p) * inv((n - m)! % p) %p

可用 exgcd 求逆元.
单组数据可直接算，但多组数据且范围较大时，时间消耗大，打表又消耗了大量空间，有局限性。

## 解法3：费马小定理

当 p 为素数时， a ^ (p - 2) 是 a % p 的逆元.

可用快速幂取模替换解法2的 exgcd，但局限性相同。

## 解法4：卢卡斯定理

当 p 是素数时

      C(n, m) % p
    = C(n % p, m % p) * C(n / p, m / p) % p
    = (C(n % p, m % p) % p) * (C(n / p, m / p) % p)

显然这是一个递归计算式，而且还是尾递归.

每次需要求解的 C(n % p, m % p) % p 的数据范围一定在 [0, p) 内.
当 p 不是很大(1e5)时，可以预打表，直接计算.


### Lucas实现：

    r = C(n ,m) % p    

定义状态

    (t, a, b)

    r = t * C(a, b) % p (循环不变式)

状态转移 

        (t,                       a,     b    )
    =>  (t * C(a % p, b % p) % p, a / p, b / p)

初始状态 

    (1, n, m)

转移后

    (C(n % p, m % p) % p,  n / p, m / p)

由归纳法和卢卡斯定理得循环不变式成立.

如果当前状态可以直接导出 r ，则终止状态转移.

    (t, a, b)

    (t = 0) => r = t * _ = 0
    (a < b) => r = t * 0 = 0
    (a = b) => r = t * 1 = t
    (b = 0) => r = t * 1 = t

## 代码

```c++
ll lucas(const ll n, const ll m, const ll p) {
    register ll t = 1, a = n, b = m;
    while (t) {
        if (a < b)
            return 0;
        if (a == b || b == 0)
            return t;

        t *= C(a % p, b % p, p);
        a /= p, b /= p;
    }
    return 0;
}
```