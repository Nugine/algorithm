#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

map<int, map<int, bool>> m;

int qpow(int b, int p) {
    int r = 1;
    while (p) {
        if (p & 1) {
            r *= b;
        }
        b *= b;
        p >>= 1;
    }
    return r;
}

int table[][2] = {{0, 0}, {1, 1}, {2, 2}, {2, 0}, {0, 2}};

void dfs(int ox, int oy, int n) {
    if (n == 1) {
        m[ox][oy] = true;
    } else {
        int size = qpow(3, n - 2);
        for (auto a : table) {
            dfs(ox + size * a[0], oy + size * a[1], n - 1);
        }
    }
}

int main() {
    vector<int> v;
    int n;
    while (cin >> n) {
        v.push_back(n);
    }
    n = *max_element(v.begin(), v.end());
    dfs(1, 1, n);

    for (auto n : v) {
        int i, j;
        int size = qpow(3, n - 1);

        asc(i, 1, size) {
            asc(j, 1, size) {
                if (m[i][j]) {
                    putchar('X');
                } else {
                    putchar(' ');
                }
            }
            putchar('\n');
        }
        cout << "-\n";
    }
}