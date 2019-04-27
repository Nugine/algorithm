#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, b;
        cin >> n >> b;

        int i;
        bool ans = false;
        for (i = 1; i <= n; ++i) {
            int ak;
            cin >> ak;
            if ((ak + b) % 7 == 0) {
                ans = true;
            }
        }
        if (ans) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}