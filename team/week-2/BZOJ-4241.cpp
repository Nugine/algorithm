#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
typedef long long ll;

const int E5 = 1e5 + 7;

int N, Q;
int x[E5];
struct Query {
    int l, r, idx;
} q[E5];
int id[E5];
int block_size;
int block_num;
int blk[E5];
ll res[E5];
int cnt[E5];
ll ans;

bool comp(const Query &a, const Query &b) {
    if (blk[a.l] != blk[b.l]) {
        return blk[a.l] < blk[b.l];
    } else {
        return a.r < b.r;
    }
}

inline void add(const int pos) {
    ++cnt[id[pos]];
    ans = max(ans, (ll(cnt[id[pos]]) * x[pos]));
}

inline void del(const int pos) { --cnt[id[pos]]; }

inline ll solve(const int l, const int r) {
    // printf("solve: [%d, %d]\n", l, r);
    register int i;
    asc(i, l, r) { cnt[id[i]] = 0; }
    ans = 0;
    asc(i, l, r) {
        ++cnt[id[i]];
        ans = max(ans, ll(cnt[id[i]]) * x[i]);
    }
    // printf("[%d, %d] = %lld\n", l, r, ans);
    return ans;
}

void solveBlk(int bl, int br, int block_id) {
    int i;
    asc(i, bl, br) {
        Query &qi = q[i];
        if (blk[qi.r] == block_id) {
            res[qi.idx] = solve(qi.l, qi.r);
        } else {
            break;
        }
    }

    if (i > br) {
        return;
    }

    int R = min(N, block_id * block_size);
    int j, L = -1;
    asc(j, i, br) { L = max(L, q[j].l); }
    ++L;
    L = (L > R + 1) ? (R + 1) : (L);
    memset(cnt, 0, sizeof(cnt));
    int qr = R;
    int ql = L;
    ans = solve(L, R);

    asc(i, i, br) {
        Query &qi = q[i];
        while (qr < qi.r) {
            ++qr;
            add(qr);
        }
        ll tmp = ans;
        while (ql > qi.l) {
            --ql;
            add(ql);
        }
        res[qi.idx] = ans;

        while (ql < L) {
            del(ql);
            ++ql;
        }
        ans = tmp;
    }
}

int main() {
    // freopen("in", "r", stdin);

    register int i;
    static int tmp[E5];

    scanf("%d %d", &N, &Q);
    block_size = sqrt(double(N));
    asc(i, 1, N) {
        scanf("%d", &x[i]);
        tmp[i] = x[i];
        blk[i] = (i - 1) / block_size + 1;
        block_num = blk[i];
    }
    sort(tmp + 1, tmp + N + 1);
    int tot = unique(tmp + 1, tmp + N + 1) - tmp - 1;
    asc(i, 1, N) { id[i] = lower_bound(tmp + 1, tmp + tot + 1, x[i]) - tmp; }
    asc(i, 1, Q) {
        int l, r;
        scanf("%d %d", &l, &r);
        q[i] = Query{l, r, i};
    }
    sort(q + 1, q + Q + 1, comp);

    // printf("N: %d, Q: %d\n", N, Q);

    register int j;
    asc(i, 1, Q) {
        int block_id = blk[q[i].l];
        asc(j, i + 1, Q) {
            if (blk[q[j].l] != block_id) {
                break;
            }
        }
        --j;
        solveBlk(i, j, block_id);
        i = j;
    }

    asc(i, 1, Q) { printf("%lld\n", res[i]); }
}
