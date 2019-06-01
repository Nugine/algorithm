#include <iostream>
using namespace std;

int N, K;

int solve(void) {
    int money = 0, cost = 200, i;
    for (i = 1; i <= 20; ++i) {
        money += N;
        cost += K;
        if (money >= cost) {
            return i;
        }
    }
    return -1;
}

int main() {
    while (cin >> N >> K) {
        int ans = solve();
        if (ans > 0) {
            cout << ans << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
}
