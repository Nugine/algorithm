#include <iostream>
using namespace std;

int main() {
    char c1;
    char c2;
    while ((c1 = getchar()) != EOF) {
        if (c1 == '0') {
            c2 = 0x01;
        } else {
            c2 = 0x02;
        }
        while ((c1 = getchar()) != '\n') {
            if (c1 == '0') {
                c2 ^= 0x01;
            } else {
                c2 ^= 0x02;
            }
        }
        if (c2 == 0x03) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}
