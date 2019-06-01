#include <cstring>
#include <iostream>
#include <signal.h>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))

string s1;
string s2;

void zip(string &s) {
    int l = s.length();
    int i, j = 0;
    rng(i, 0, l) {
        char c = s[i];
        if ('A' <= c && c <= 'Z') {
            s[j++] = c - 'A' + 'a';
        } else if ('a' <= c && c <= 'z') {
            s[j++] = c;
        } else if (c == ' ') {
            continue;
        } else {
            raise(SIGUSR1);
        }
    }
    s.erase(j);
}

void solve() {
    getline(cin, s1);
    getline(cin, s2);

    zip(s1);
    zip(s2);

    int cmp = (s1 == s2);
    if (cmp) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int n;
    int i;
    while (cin >> n) {
        getline(cin, s1);
        asc(i, 1, n) { solve(); }
    }
}
