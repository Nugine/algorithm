#include <algorithm>
#include <cstdio>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rd(x) scanf("%d", &(x))

struct Num {
    int idx, val;
} a[200000 + 7];
int n;

struct Seq {
    int s, e;
} seq[200000 + 7];
int len;

bool comp(const Num &a, const Num &b) {
    return (a.val < b.val) || (a.val == b.val && a.idx < b.idx);
}

int main() {
    // freopen("in", "r", stdin);

    rd(n);
    int i;

    asc(i, 1, n) {
        a[i].idx = i;
        rd(a[i].val);
    }

    if (n == 1 || n == 2) {
        printf("%d\n", 1);
        return 0;
    }

    sort(a + 1, a + n + 1, comp);

    len = 1;
    seq[1].s = seq[1].e = a[1].idx;
    asc(i, 2, n) {
        if (a[i].val != a[i - 1].val) {
            seq[len].e = a[i - 1].idx;
            seq[++len].s = a[i].idx;
        }
    }
    seq[len].e = a[n].idx;

    // asc(i, 1, n) { printf("%d  ", a[i].val); }
    // putchar('\n');
    // asc(i, 1, n) { printf("%d  ", a[i].idx); }
    // putchar('\n');
    // asc(i, 1, len) { printf("%d  ", seq[i].s); }
    // putchar('\n');
    // asc(i, 1, len) { printf("%d  ", seq[i].e); }
    // putchar('\n');

    int ans = 0;
    int flag = -1;
    asc(i, 2, len) {
        if (flag == -1) {
            if (seq[i].e < seq[i - 1].s) {
                continue;
            } else {
                flag = 1;
                ++ans;
            }
        } else {
            if (seq[i].s > seq[i - 1].e) {
                continue;
            } else {
                flag = -1;
            }
        }
    }
    if (flag == -1) {
        ++ans;
    }

    printf("%d\n", ans);

    return 0;
}