#include <cstdio>
typedef long long ll;

inline ll qread(void) {
    ll x = 0, flag = 1;
    char c;
    for (;;) {
        c = getchar_unlocked();
        if (c == '-') {
            flag = -1;
            break;
        }
        if (c >= '0' && c <= '9') {
            break;
        }
    }
    for (;;) {
        x = x * 10 + (c ^ '0');
        c = getchar_unlocked();
        if (c >= '0' && c <= '9') {
            continue;
        }
        return x * flag;
    }
}