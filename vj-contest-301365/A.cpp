//  https://www.cnblogs.com/acerkoo/p/9539700.html

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int S[1000000 + 7];
int maxs[1000000 + 7] = {1 << 31};

void I(stack<int> &before, int x) {
    before.push(x);
    int i = before.size();
    S[i] = S[i - 1] + x;
    maxs[i] = max(maxs[i - 1], S[i]);
    // cout << i << " " << S[i] << " " << maxs[i] << endl;
}

void D(stack<int> &before) {
    if (!before.empty()) {
        before.pop();
    }
}

void L(stack<int> &before, stack<int> &after) {
    if (!before.empty()) {
        int x = before.top();
        before.pop();
        after.push(x);
    }
}

void R(stack<int> &before, stack<int> &after) {
    if (!after.empty()) {
        int x = after.top();
        after.pop();
        I(before, x);
    }
}

int Q(int k) { return maxs[k]; }

int main() {
    // freopen("in", "r", stdin);

    int q;
    while (scanf("%d", &q) > 0) {
        getchar();

        stack<int> before, after;
        char op;
        int t;
        int ans;
        while (q--) {
            op = getchar();
            switch (op) {
            case 'I':
                scanf("%d", &t);
                I(before, t);
                break;
            case 'D':
                D(before);
                break;
            case 'L':
                L(before, after);
                break;
            case 'R':
                R(before, after);
                break;
            case 'Q':
                scanf("%d", &t);
                ans = Q(t);
                printf("%d\n", ans);
                break;
            default:
                break;
            }
            getchar();
        }
    }
    return 0;
}
