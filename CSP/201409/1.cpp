#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int n;
int a[1024];

int main() {
    cin >> n;

    int i;
    asc(i, 1, n) { cin >> a[i]; }

    sort(a + 1, a + n + 1);

    int cnt = 0;
    asc(i, 2, n) { cnt += (a[i - 1] + 1 == a[i]); }

    cout << cnt << '\n';

    return 0;
}
