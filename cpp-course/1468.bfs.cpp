#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef unsigned long long ull;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

vector<string> vs[30];

void init() {
    for (auto &v : vs) {
        v.clear();
    }

    deque<string> q;
    char c;
    asc(c, '1', '9') {
        string s;
        s += c;
        q.push_back(s);
    }
    for (auto &x : q) {
        vs[1].push_back(x);
    }

    int i, j;
    asc(i, 2, 24) {
        int len = q.size();
        asc(j, 1, len) {
            auto &s = q.front();

            int m = 0;
            for (auto ch : s) {
                m = (m * 10 + (ch ^ '0')) % i;
            }
            asc(c, '0', '9') {
                if ((m * 10 + (c ^ '0')) % i == 0) {
                    q.push_back(s + c);
                }
            }

            q.pop_front();
        }
        for (auto &x : q) {
            vs[i].push_back(x);
        }
    }
}

int main() {
    init();
    int n;
    while (cin >> n) {
        for (auto &s : vs[n]) {
            cout << s << endl;
        }
    }
}
