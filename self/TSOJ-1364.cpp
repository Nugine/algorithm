#include <iostream>
#include <map>
using namespace std;

template <typename T> void qread(T &a) {
    char c = getchar();
    int s = 1;
    while (c < '0' || c > '9') {
        if (c == '-') {
            s = -1;
        }
        c = getchar();
    }
    T x = 0;
    while (c >= '0' && c <= '9') {
        x = 10 * x + c - '0';
        c = getchar();
    }
    a = s * x;
}

int main() {
    int N;
    while (cin >> N) {
        map<int, int> table;
        while (N--) {
            int score;
            qread(score);
            ++table[score];
        }
        for (auto &p : table) {
            printf("%d %d\n", p.first, p.second);
        }
    }
}
