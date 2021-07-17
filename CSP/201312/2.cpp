#include <cstdio>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

char s[64];

int main() {
    cin >> s;

    int code = 0;
    code += (s[0] - '0') * 1;
    code += (s[2] - '0') * 2;
    code += (s[3] - '0') * 3;
    code += (s[4] - '0') * 4;
    code += (s[6] - '0') * 5;
    code += (s[7] - '0') * 6;
    code += (s[8] - '0') * 7;
    code += (s[9] - '0') * 8;
    code += (s[10] - '0') * 9;
    code %= 11;

    code = (code == 10) ? ('X') : (code + '0');

    if (s[12] == code) {
        cout << "Right\n";
    } else {
        s[12] = code;
        cout << s << '\n';
    }
}
