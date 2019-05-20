#include <cstdio>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

template <typename T> T qread(void) {
    char c = getchar();
    T a = 0, s = 1;
    while (c < '0' || c > '9') {
        if (c == '-') {
            s = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        a = 10 * a + c - '0';
        c = getchar();
    }
    return s * a;
}

int a[2000000 + 7];
int n;
int k;

int q[2000000 + 7];
int head, tail;

int main() {
    n = qread<int>();
    k = qread<int>();

    int i;
    asc(i, 1, n) { a[i] = qread<int>(); }

    head = 1, tail = 0;
    asc(i, 1, n) {
        while (head <= tail && a[q[tail]] <= a[i]) {
            --tail;
        }
        q[++tail] = i;
        while (head <= tail && q[head] <= i - k) {
            ++head;
        }
        if (i >= k) {
            printf("%d\n", a[q[head]]);
        }
    }
    return 0;
}