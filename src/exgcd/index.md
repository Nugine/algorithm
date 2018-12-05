# 扩展欧几里得递推算法的证明与实现

## 欧几里得算法

gcd(a, b) 表示 整数 a 与 b 的最大公约数.

有

    t = a % b
    gcd(a, b) = gcd(b, a % b) = gcd(b, t)

证明略.

### 如何写出递推版的 gcd 算法？

gcd 接受变量元组 (a, b) 作为输入，输出最大公约数 ( r ).

我们很难直接计算出 r，但可以通过一些中间步骤逐步计算得到 r.

我们定义一个中间状态

    (c, d, t)

    t = c % d

定义一个状态转移过程，将一个状态映射到下一个状态.

       (c, d, t    )
    => (d, t, d % t)


将初始状态赋值为 (a, b, a % b)，则

    r = gcd(a, b)

进行状态转移

       (a, b,     a % b      )
    => (b, a % b, b % (a % b))

此时

    r = gcd(b, a % b) = gcd(a, b)

由归纳法，可得，在任意一个中间状态 (c, d, t) 时，有

    r = gcd(c, d)

状态转移不能无限进行下去，要有一个终止条件，即 t = 0.

当 t = c % d = 0 时，显然 d | c， r = gcd(c, d) = d.

在最终状态 (c, d, 0) 时， d 就是最大公约数 r.


### 代码

```c++
int gcd(const int a,const int b) {
    int c = a, d = b, t = a % b;
    while (t) {
        c = d, d = t, t = c % d;
    }
    return d;
}
```

实际上，可以减少变量个数，直接使用输入时定义的变量 a, b 存放中间状态，即我们通常所见的gcd实现。

## 扩展欧几里得算法

设

    r = gcd(a, b) = a * x + b * y

则扩展欧几里得算法可以在求出 r 的同时，得出 r = a * x + b * y 的一组整数解。

### 如何写出递推版的 exgcd 算法？

exgcd 是一个映射

    (a,b) => (r, x, y)

可以这样定义中间状态

    (c, d, q, t, x, y)

    q = c / d
    t = c % d = a * x + b * y

继承 gcd 的状态转移过程

    (c, d, q, t, x, y) => (d, t, d / t, d % t, x', y')

当 d % t = 0 时， r = gcd(c, d) = gcd(d, t) = t.
此时该状态保证 r = t = a * x + b * y， 即得解.

但有个问题，如何递推计算 x, y？

    t = a * x + b * y
    d % t = a * x' + b * y'

      d % t
    = d - (d / t) * t
    = d - (d / t) * (a * x + b * y)
    
无法计算 x', y'.

又注意到上式中的 d 阻断了递推，因此有没有办法用 x, y 表示 d 呢？

这就是通常的 exgcd 递推算法.

定义状态

    (c, d, q, t, x0, y0, x1, y1)
    
    q = c / d
    t = c % d
    c = a * x0 + b * y0
    d = a * x1 + b * y1

状态转移

       (c, d, q,     t,     x0, y0, x1,          y1     )
    => (d, t, d / t, d % t, x1, y1, x0 - q * x1, y0 - q * y1)

证明： 状态转移不会破坏状态定义

       t
    =  c - q * d
    = (a * x0 + b * y0) - q * (a * x1 + b * y1)
    = (x0 - q * x1) * a + (y0 - q * y1) * b

    d = a * x1 + b * y1
    t = (x0 - q * x1) * a + (y0 - q * y1) * b

因此转移后的状态仍满足定义。

初始状态

    (a, b, a / b, a % b, 1, 0, 0, 1)

由归纳法可得，在任意一个中间状态，有

    r = gcd(c, d)

当 t = c % d = 0 时, d | c, r = gcd(c, d) = d.

    r = d = a * x1 + b * y1 = a * x + b * y

输出为 (d, x1, y1)

### 代码

```python
def exgcd(a, b):
    c, d, q, t, x0, y0, x1, y1 = a, b, a // b, a % b, 1, 0, 0, 1
    while t:
        c, d, q, t, x0, y0, x1, y1 = d, t, d // t, d % t, x1, y1, x0 - q * x1, y0 - q * y1
    return d, x1, y1
```

```c++
int exgcd(int a, int b, int &x, int &y) {
    register int q = a / b, t = a % b;
    register int x0 = 1, y0 = 0, x1 = 0, y1 = 1;
    while (t) {
        a = b;
        b = t;
        t = x0, x0 = x1, x1 = t - q * x1;
        t = y0, y0 = y1, y1 = t - q * y1;
        q = a / b;
        t = a % b;
    }
    x = x1, y = y1;
    return b;
}
```