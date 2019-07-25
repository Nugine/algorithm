

$$
a_1, a_2, \cdots, a_r, a_{r+1}
$$

若已求到  $ans(r)$，则 $ans(r+1) = ans(r) + solve(r+1) $

设前缀和 $ps(i) = \sum_{k=1}^{i}{a_k}$

设区间 $I[l,r]$ 的最大值为 $max(I[l,r])$

$ solve(r+1) = \sum_{i=1}^r{judge(i,r+1)}$

$judge(i,r+1) = (max(I[i,r+1]) \le \lfloor sum(I[i,r+1])/
2 \rfloor) = (2max(I[i,r+1])+ps(i-1)\le ps(r+1))$

##### 第一种情况
若 $a_{r+1}\ge max(I[1,r])$

则 $judge(i,r+1)=(ps(i-1)\le ps(r) - a_{r+1})$

$ps(i-1)$严格单调，二分查找

$solve(r+1)$ 为 $O(logn)$

### 第二种情况
