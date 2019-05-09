#include <cstdio>

int qread() {
    char c = getchar();
    int a = 0, s = 1;
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