// https://www.cnblogs.com/whyandinside/archive/2012/08/26/2657360.html

#include <iostream>
using namespace std;

const char *fmt = "%c -> %c\n";

void hanoi_3(char s, char m, char d, int n) {
    if (n > 1) {
        hanoi_3(s, d, m, n - 1);
        printf(fmt, s, d);
        hanoi_3(m, s, d, n - 1);
    } else {
        printf(fmt, s, d);
    }
}

/**
 * hanoi4(n) = 1, n = 1
 * hanoi4(n) = max{ 2 * hanoi4(n - k) + 2 ^ k - 1 for k in [1, n] }, n > 1
 */
void hanoi_4(char s, char m1, char m2, char d, int n) {
    if (n > 1) {
        const int k = n / 2; // any k in [1, n]
        hanoi_4(s, m2, d, m1, n - k);
        hanoi_3(s, m2, d, k);
        hanoi_4(m1, s, m2, d, n - k);
    } else {
        printf(fmt, s, d);
    }
}

int main() {
    hanoi_4('A', 'B', 'C', 'D', 4);
    return 0;
}
