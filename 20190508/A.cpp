// <https://cn.vjudge.net/contest/300473>

#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef unsigned long long ull;

map<string, ull> table;

const ull MASK = 0x7fffffffffff;

int main() {
    string op;
    string v1, v2;
    ull val;
    while (cin >> op) {

        if (op == "def") {
            cin >> v1 >> val;
            // table[v1] = val;
            table.insert(make_pair(v1, val));
        } else if (op == "add") {
            cin >> v1 >> v2;
            table[v1] += table[v2];
            table[v1] &= MASK;
        } else if (op == "sub") {
            cin >> v1 >> v2;
            table[v1] -= table[v2];
            table[v1] &= MASK;
        } else if (op == "mul") {
            cin >> v1 >> v2;
            table[v1] *= table[v2];
            table[v1] &= MASK;
        } else if (op == "div") {
            cin >> v1 >> v2;
            table[v1] /= table[v2];
            table[v1] &= MASK;
        } else if (op == "mod") {
            cin >> v1 >> v2;
            table[v1] %= table[v2];
            table[v1] &= MASK;
        }
        ull ans = table[v1];
        cout << v1 << " = " << ans << endl;
    }
    return 0;
}
