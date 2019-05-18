#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
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

int qread() {
    char c = getchar();
    int a = 0, s = 1;
    while (c < '0' || c > '9') {
        if (c == '-') {
            s = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        a = 10 * a + c - '0';
        c = getchar();
    }
    return s * a;
}

int n;
struct Rect {
    int x1, y1;
    int x2, y2;
};

Rect rects[100000 + 7];

int comp(const Rect &a, const Rect &b) {
    // by left down
    if (a.x1 < b.x1)
        return true;
    if (a.x1 == b.x1)
        return a.y1 < b.y1;
    return false;
}

int solve();
int main() {
    // freopen("in", "r", stdin);

    n = qread();
    int i;
    asc(i, 1, n) {
        Rect &r = rects[i];
        r.x1 = qread();
        r.y1 = qread();
        r.x2 = qread();
        r.y2 = qread();
    }
    sort(rects + 1, rects + n + 1, comp);

    // asc(i, 1, n) {
    //     Rect &r = rects[i];
    //     printf("%d: %d %d %d %d\n", i, r.x1, r.y1, r.x2, r.y2);
    // }
    int ans = solve();
    pdln(ans);

    return 0;
}

inline int judge(const Rect &lhs, const Rect &rhs) {

    if (lhs.x1 == rhs.x1) {
        if (lhs.y1 == rhs.y1) {
            return 1;
        } else if (lhs.y1 < rhs.y1) {
            return rhs.y2 >= lhs.y1;
        } else {
            // unreachable
        }
    } else {
        // lhs.x1 < rhs.x1
        if (lhs.y1 == rhs.y1) {
            return lhs.x2 >= rhs.x1;
        } else if (lhs.y1 < rhs.y1) {
            return (lhs.x2 >= rhs.x1 && lhs.y2 >= rhs.y1 && lhs.x2 <= rhs.x2 &&
                    lhs.y2 <= rhs.y2);
        } else {
            // lhs.y1 > rhs.y1
            if (rhs.x1 > lhs.x2) {
                return 0;
            } else {
                // lhs.x2 >= rhs.x1
                return rhs.y2 >= lhs.y1;
            }
        }
    }
    return 0; // unreachable
}

inline int isFar(const Rect &lhs, const Rect &rhs) { return lhs.x2 < rhs.x1; }

int solve() {
    deque<Rect *> dq;

    int i, j, len;
    asc(i, 1, n) {
        Rect &rhs = rects[i];
        len = dq.size();
        rng(j, 0, len) {
            Rect &lhs = *dq.front();

            if (judge(lhs, rhs)) {
                return 1;
            }

            if (!isFar(lhs, rhs)) {
                dq.push_back(&lhs);
            }
            dq.pop_front();
        }
        dq.push_back(&rhs);
    }
    return 0;
}