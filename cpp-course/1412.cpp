#include <iostream>
using namespace std;

int solve(int n, int i, int j, int s) {
    for (;;) {
        if (i == 1) {
            return s + j - 1;
        }
        if (j == n) {
            return s + (n - 1) + (i - 1);
        }
        if (i == n) {
            return s + (n - 1) * 2 + (n - j);
        }
        if (j == 1) {
            return s + (n - 1) * 3 + (n - i);
        }

        s = s + (n - 1) * 4;
        n = n - 2;
        i = i - 1;
        j = j - 1;
    }
}

int main() {
    int n, i, j;
    while (cin >> n >> i >> j) {
        cout << solve(n, i, j, 1) << endl;
    }
}
