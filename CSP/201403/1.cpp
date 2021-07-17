#include <cstdio>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int n;

bool buf[2048] = {0};

int main() {
    cin >> n;

    int i;
    int t;
    bool *a = &buf[1024];
    int cnt = 0;

    asc(i, 1, n) {
        cin >> t;
        cnt += a[-t];
        a[t] = true;
    }

    cout << cnt << '\n';

    return 0;
}