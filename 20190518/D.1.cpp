#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll get(ll a,ll b,ll c,ll n){
    if (n<=0) return 0;
    if (n==1) return b/c ;
    ll tmp = 0;
    tmp += a/c*(n-1)*n/2+ b/c*n;
    a = a%c;
    b = b%c;
    if (a==0) return tmp;
    return tmp+get(c,(a*n+b)%c,a,(a*n+b)/c);
}

int main() {

    int T;
    ll p, q, n;
    scanf("%d", &T);

    while (T--) {
        scanf("%lld %lld %lld", &p, &q, &n);
        ll ans = (p * n * (n + 1) / 2 - q * get(p, p, q, n));
        printf("%lld\n", ans);
    }
}