#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> vs[120];

int main() {
    freopen("in", "r", stdin);
    int m, n;
    cin >> m >> n;

    int u, v;
    while (cin >> u >> v) {
        if (u == -1 && v == -1) {
            break;
        }

        vs[u].push_back(v);
    }

    for (int i = 1; i <= m; ++i) {
        cout << i;
        for (auto v : vs[i]) {
            cout << " " << v;
        }
        cout << endl;
    }

    freopen("out", "r", stdin);
    int checked[120] = {0};
    int ans;
    cin >> ans;

    while (cin >> u >> v) {
        if (checked[u] || find(vs[u].begin(), vs[u].end(), v) == vs[u].end()) {
            cout << "WA" << endl;
            return 0;
        }
        checked[u] = 1;
    }
    cout << "AC" << endl;
    return 0;
}