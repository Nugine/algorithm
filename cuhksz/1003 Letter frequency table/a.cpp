#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define asc(i, s, e) for (i = (s); i <= (e); ++i)

int cnt[256];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int i;
    char c;
    asc(i, 1, n) {
        cin >> c;
        cnt[int(c)]++;
    }

    asc(c, 'A', 'Z') { printf("%c: %d\n", c, cnt[int(c)]); }

    return 0;
}