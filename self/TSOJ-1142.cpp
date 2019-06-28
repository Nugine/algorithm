#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    string src;
    cin >> src;
    vector<pair<int, char>> v;
    char now = '\0';
    for (auto c : src) {
        if (c == now) {
            auto &p = v.back();
            ++p.first;
        } else {
            v.push_back(make_pair(1, c));
            now = c;
        }
    }
    string ans;
    for (auto &p : v) {
        if (p.first != 1) {
            ans += to_string(p.first);
        }
        ans += p.second;
    }
    cout << ans << endl;
}

int main() {
    int T;
    while (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}