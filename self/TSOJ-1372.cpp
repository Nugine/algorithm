#include <cstdio>
#include <iostream>
using namespace std;

inline int base_from_char(char c) {
    if (c <= '9' && c >= '0') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

int main() {
    int m, k;
    while (scanf("%d %d", &m, &k) > 0) {
        getchar();
        int ans = 0;
        char c;
        while ((c = getchar()) != '\n') {
            ans = ans * m + base_from_char(c);
            ans %= k;
        }
        printf("%d\n", ans);
    }
    return 0;
}