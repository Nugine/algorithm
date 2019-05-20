#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

const int N = 3e5 + 5;
const int MAX = 1e6 + 5;

int unit;
int cnt[MAX];
int arr[N];
int res[N];
int ans = 0;
int n, m;

struct Node {
    int l, r;
    int id;
} q[N];

bool comp(const Node &a, const Node &b) {
    if (a.l / unit != b.l / unit) {
        return a.l / unit < b.l / unit;
    } else {
        return a.r < b.r;
    }
}

inline void add(int pos) {
    ++cnt[arr[pos]];
    if (cnt[arr[pos]] == 1) {
        ++ans;
    }
}

inline void remove(int pos) {
    --cnt[arr[pos]];
    if (cnt[arr[pos]] == 0) {
        --ans;
    }
}

int main() {
    scanf("%d", &n);
    unit = sqrt(n);

    int i;
    asc(i, 1, n) { scanf("%d", &arr[i]); }

    scanf("%d", &m);

    asc(i, 1, m) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].id = i;
    }

    sort(q + 1, q + m + 1, comp);

    int L = q[1].l;
    int R = L - 1;

    asc(i, 1, m) {
        while (L > q[i].l) {
            --L;
            add(L);
        }
        while (L < q[i].l) {
            remove(L);
            ++L;
        }
        while (R > q[i].r) {
            remove(R);
            --R;
        }
        while (R < q[i].r) {
            ++R;
            add(R);
        }
        res[q[i].id] = ans;
    }
    asc(i, 1, m) { printf("%d\n", res[i]); }
}
