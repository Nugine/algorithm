#include <iostream>
using namespace std;
typedef double db;

db solve(db r1, db r2, db d1) {
    db t1 = d1 * d1 * d1 + 3 * r1 * r1 * d1 - 3 * r1 * d1 * d1;

    db l = 0, r = r2;
    while ((r - l) > 1e-5) {
        db mid = (r + l) / 2;
        db d2 = mid;
        db t2 = d2 * d2 * d2 + 3 * r2 * r2 * d2 - 3 * r2 * d2 * d2;
        if (t2 < t1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int r1, r2, d;
        cin >> r1 >> r2 >> d;
        db ans = solve(r1, r2, d);
        cout << ans << '\n';
    }
}