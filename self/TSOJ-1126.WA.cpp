#include <algorithm>
#include <iostream>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))

const int N = 20;

int main() {
    int arr[N];
    int n;
    while (cin >> n) {
        int i;
        asc(i, 1, n) {
            arr[i] = i;
            putchar(i + '0');
        }
        putchar('\n');
        while (next_permutation(arr + 1, arr + n + 1)) {
            asc(i, 1, n) { putchar(arr[i] + '0'); }
            putchar('\n');
        }
    }
}