#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

vector<string> vs[30];

char s[100];

bool judge(int i) {
    int j;
    int m = 0;
    asc(j, 1, i) { m = (m * 10 + (s[j] - '0')) % i; }
    return m == 0;
}

void dfs(int i) {
    if (i > 24) {
        return;
    }
    asc(s[i], '0', '9') {
        if (judge(i)) {
            string num;
            int j;
            asc(j, 1, i) { num += s[j]; }
            vs[i].push_back(num);
            dfs(i + 1);
        }
    }
}

int main() {
    asc(s[1], '1', '9') {
        dfs(2);
        string num;
        num += s[1];
        vs[1].push_back(num);
    }
    int n;
    while (cin >> n) {
        for (auto &num : vs[n]) {
            cout << num << endl;
        }
    }
}