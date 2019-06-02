#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

int m, n;

struct Node {
    int next;
};
Node a[1007];

int solve(void) {
    int i, j;
    asc(i, 1, m - 1) { a[i].next = i + 1; }
    a[m].next = 1;

    int p = m;
    asc(i, 1, m - 1) {
        asc(j, 2, n) { p = a[p].next; }
        a[p].next = a[a[p].next].next;
    }
    return p;
}

int main() {
    while (cin >> m >> n) {
        cout << solve() << endl;
    }
}
