#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
typedef unsigned long long ull;

const ull M = 0xffffffff;

bool checked_mul(ull lhs, ull rhs, ull &r) {
    ull a1 = lhs >> 32, b1 = rhs >> 32;
    ull a0 = lhs & M, b0 = rhs & M;

    if ((a1 && b1) || ((a0 * b0 >> 32) + b1 * a0 + b0 * a1) >> 32) {
        r = 0;
        return true;
    } else {
        r = lhs * rhs;
        return false;
    }
}

int main() {
    static ull a[70] = {1}, b[70] = {1};
    static int lena, lenb;
    int i, j;

    rng(i, 1, 64) {
        if (checked_mul(a[i - 1], 2, a[i])) {
            break;
        }
    }
    lena = i;

    // rng(i, 0, lena) { cout << i << ' ' << a[i] << endl; }

    rng(i, 1, 64) {
        if (checked_mul(b[i - 1], 3, b[i])) {
            break;
        }
    }
    lenb = i;

    // rng(i, 0, lenb) { cout << i << ' ' << b[i] << endl; }

    static vector<ull> v;
    rng(i, 0, lena) {
        rng(j, 0, lenb) {
            ull t;
            if (checked_mul(a[i], b[j], t)) {
                break;
            } else {
                v.push_back(t);
            }
        }
    }
    sort(v.begin(), v.end());
    // cout << v.size() << endl;

    // for (auto x : v) {
    //     cout << x << endl;
    // }

    ull n, m;
    while (cin >> n >> m) {
        int i = lower_bound(v.begin(), v.end(), n) - v.begin();
        cout << (i) << endl;
        cout << v[m - 1] << endl;
    }
}
