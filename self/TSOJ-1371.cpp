#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int m = 2, k = 3;
    char c;
    while ((c = getchar()) != EOF) {
        int ans = c - '0';
        while ((c = getchar()) != '\n') {
            ans = ans * m + (c - '0');
            ans %= k;
        }
        if (ans == 0) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
