// https://www.cnblogs.com/chensongxian/p/7059802.html
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

double solve(char src[]);

int main() {
    // freopen("in", "r", stdin);

    char src[250];
    // https://www.cnblogs.com/qq-star/p/3880596.html
    while (cin.getline(src, sizeof(src)) && strcmp(src, "0")) {
        double ans = solve(src);
        printf("%.2lf\n", ans);
    }
    return 0;
}

struct Token {
    int type;
    union {
        double num;
        char op;
    };

    Token(double num) : num(num) { type = 1; }
    Token(char op) : op(op) { type = 2; }
};

unordered_map<char, int> table = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

double solve(char src[]) {
    deque<Token> infix;
    int len = strlen(src);
    for (int i = 0; i < len; ++i) {
        if (isdigit(src[i])) {
            double t = 0;
            while (i < len && isdigit(src[i])) {
                t = t * 10 + (src[i] ^ '0');
                ++i;
            }
            --i;
            infix.emplace_back(t);
        } else if (src[i] == ' ') {
            continue;
        } else if (table.count(src[i])) {
            infix.emplace_back(src[i]);
        }
    }

    stack<char> stk;
    deque<Token> postfix;
    while (!infix.empty()) {
        Token tk = infix.front();
        infix.pop_front();

        if (tk.type == 1) {
            postfix.push_back(tk);
        } else {
            if (stk.empty()) {
                stk.push(tk.op);
            } else {
                if (table[stk.top()] < table[tk.op]) {
                    stk.push(tk.op);
                } else {
                    while (!stk.empty() && table[stk.top()] >= table[tk.op]) {
                        postfix.emplace_back(stk.top());
                        stk.pop();
                    }
                    stk.push(tk.op);
                }
            }
        }
    }
    while (!stk.empty()) {
        postfix.emplace_back(stk.top());
        stk.pop();
    }

    stack<double> num;
    while (!postfix.empty()) {
        Token tk = postfix.front();
        postfix.pop_front();

        if (tk.type == 1) {
            num.push(tk.num);
        } else {
            double rhs = num.top();
            num.pop();
            double lhs = num.top();
            num.pop();

            double ans;
            switch (tk.op) {
            case '+':
                ans = lhs + rhs;
                break;
            case '-':
                ans = lhs - rhs;
                break;
            case '*':
                ans = lhs * rhs;
                break;
            case '/':
                ans = lhs / rhs;
                break;
            }
            num.push(ans);
        }
    }
    return num.top();
}