#include <algorithm>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

const int N = 20;
char arr[N];
int n;

void solve(int s) {
    int i;
    if (s == n) {
        printf("%s\n", arr + 1);
    } else {
        asc(i, s, n) {
            swap(arr[i], arr[s]);
            solve(s + 1);
            swap(arr[i], arr[s]);
        }
    }
}

int main() {
    int i;
    while (cin >> n) {
        asc(i, 1, n) { arr[i] = i + '0'; }
        solve(1);
    }
}