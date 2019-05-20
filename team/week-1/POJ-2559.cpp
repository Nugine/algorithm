#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;
typedef long long ll;

template <typename T> T qread(void) {
    char c = getchar();
    int s = 1;
    while (c < '0' || c > '9') {
        if (c == '-') {
            s = -1;
        }
        c = getchar();
    }
    T x = 0;
    while ('0' <= c && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return s * x;
}

const int N = 100000 + 7;
ll h[N];
int n;

void solve(void);
int main() {
    // freopen("in", "r", stdin);

    while (scanf("%d", &n) > 0 && n > 0) {
        for (int i = 1; i <= n; ++i) {
            h[i] = qread<ll>();
        }
        solve();
    }
    return 0;
}

struct Rect{
    ll h,w;
};

void solve(void) {
    h[++n] = 0;
    
    stack<Rect> stk;
    ll ans = 0;

    int i;
    for (i = 1; i <= n; ++i) {
        int width=0;
        while (!stk.empty() && stk.top().h > h[i]) {
            Rect&r=stk.top();
            width+=r.w;
            ans = max(ans, r.h * width);
            stk.pop();
        }
        stk.push(Rect{h[i],1+width});
    }
    printf("%lld\n", ans);
}
