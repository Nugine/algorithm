#include <cstdio>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
typedef long long ll;

int main() {
    int N, i, ans;
    ll h, maxh;
    while (scanf("%d", &N) > 0) {
        ans = 0;
        maxh = -1;
        asc(i, 1, N) {
            scanf("%lld", &h);
            if (h > maxh) {
                ++ans;
                maxh = h;
            }
        }
        printf("%d\n", ans);
    }
}
