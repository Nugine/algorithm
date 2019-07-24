#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define pd(x) printf("%d", (x))
#define pdsp(x) printf("%d ", (x))
#define sppd(x) printf(" %d", (x))
#define pdln(x) printf("%d\n", (x))

int solve() {
    int n;
    int i;
    rd(n);

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(0);
    pq.push(0);

    asc(i, 1, n) {
        int t;
        rd(t);
        pq.push(t);
        pq.pop();
    }
    int ans = min(pq.top() - 1, n - 2);
    pdln(ans);
    return 0;
}

int main() {
    int T;
    int i;
    rd(T);
    asc(i, 1, T) { solve(); }
    return 0;
}