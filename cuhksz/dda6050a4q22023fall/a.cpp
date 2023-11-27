// #define LOCAL_DEBUG

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)
#define rng(i, s, e) for (i = (s); i < (e); ++i)
#define desc(i, s, e) for (i = (s); i >= (e); --i)
#define ordefault(a, b) (a) ? (a) : (b)
#ifdef LOCAL_DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif

const int MAXN = 1e5 + 7;
const int BITS = 17;

struct Trie01 {
    int next[MAXN * BITS][2];
    int cnt;

    void insert(uint x) {
        int p = 0;
        int i;
        desc(i, BITS - 1, 0) {
            int c = (x >> i) & 1;
            if (!next[p][c]) next[p][c] = ++cnt;
            p = next[p][c];
        }
    }

    uint max_xor(uint x) {
        uint ans = 0;
        int p = 0;
        int i;
        desc(i, BITS - 1, 0) {
            int c = (x >> i) & 1;
            if (next[p][c ^ 1]) {
                p = next[p][c ^ 1];
                ans |= (1 << i);
            } else {
                p = next[p][c];
            }
        }
        return ans;
    }
};

Trie01 trie;

int n;
uint a[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int i;
    asc(i, 1, n) { cin >> a[i]; }

    asc(i, 1, n) { trie.insert(a[i]); }

    uint ans = 0;
    asc(i, 1, n) { ans = max(ans, trie.max_xor(a[i])); }
    cout << ans << endl;
}
