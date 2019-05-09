#include <cstring>
#include <iostream>
using namespace std;

static int mem[10000 + 4];

int solve(int x);
int main() {
    memset(mem, -1, sizeof(mem));

    int x;
    while (cin >> x) {
        cout << solve(x) << endl;
    }
}

inline bool has24(int n) {
    int t;
    while (n) {
        t = n % 10;
        if (t == 2 || t == 4)
            return true;
        n /= 10;
    }
    return false;
}

int solve(int x) {

    if (mem[x] >= 0) {
        return mem[x];
    }

    int i, j, k;

    int c1 = x / 3;
    int c2;

    int ans = 0;
    for (i = 1; i <= c1; ++i) {
        if (has24(i))
            continue;

        c2 = (x - i) / 2;
        for (j = i + 1, k = x - i - j; j <= c2 && k > j; ++j, --k) {
            if (has24(j) || has24(k))
                continue;

            ++ans;
        }
    }
    return mem[x] = ans;
}
