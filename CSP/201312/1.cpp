#include <cstdio>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

int n;

int cnt[10000 + 7] = {0};

int main() {
    cin >> n;

    int i;
    int si;
    int max_cnt = 0;
    asc(i, 1, n) {
        cin >> si;
        cnt[si] += 1;
        max_cnt = max(max_cnt, cnt[si]);
    }

    asc(i, 1, 10000) {
        if (cnt[i] == max_cnt) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
