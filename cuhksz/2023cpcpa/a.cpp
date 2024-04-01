#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 0;
    int b = 0;
    for (auto c : s) {
        if (c == 'A') {
            a++;
        } else if (c == 'B') {
            b++;
        }
    }
    printf("A:%d\n", a);
    printf("B:%d\n", b);
    if (a > b) {
        printf("A wins!\n");
    } else if (a < b) {
        printf("B wins!\n");
    } else {
        printf("Draw!\n");
    }
}