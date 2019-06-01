#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))

enum TokenType { NUM, OP };
struct Token {
    TokenType type;
    union {
        double num;
        char op;
    };
    Token(double num) : num(num) { type = NUM; }
    Token(char op) : op(op) { type = OP; }
};

unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
unordered_set<char> ops = {'(', ')', '+', '-', '*', '/'};

double solve(const string &src) {
    deque<Token> infix;
    int len = src.size(), i;
    rng(i, 0, len) {
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
        } else if (ops.count(src[i])) {
            infix.emplace_back(src[i]);
        }
    }

    // for (auto tk : infix) {
    //     if (tk.type == NUM) {
    //         cout << to_string(tk.num) << ' ';
    //     } else {
    //         cout << tk.op << ' ';
    //     }
    // }
    // cout << endl;

    stack<char> stk;
    deque<Token> prefix;
    while (!infix.empty()) {
        auto tk = infix.back();
        infix.pop_back();

        if (tk.type == NUM) {
            prefix.push_front(tk);
            continue;
        }

        if (stk.empty()) {
            stk.push(tk.op);
            continue;
        }

        if (tk.op == ')') {
            stk.push(tk.op);
            continue;
        }

        if (tk.op == '(') {
            while (!stk.empty() && stk.top() != ')') {
                prefix.emplace_front(stk.top());
                stk.pop();
            }
            if (!stk.empty() && stk.top() == ')') {
                stk.pop();
            }
            continue;
        }

        if (stk.top() == ')') {
            stk.push(tk.op);
            continue;
        }

        if (priority[stk.top()] <= priority[tk.op]) {
            stk.push(tk.op);
            continue;
        }

        while (!stk.empty() && stk.top() != ')' &&
               priority[stk.top()] > priority[tk.op]) {
            prefix.emplace_front(stk.top());
            stk.pop();
        }
        stk.push(tk.op);
    }

    while (!stk.empty()) {
        prefix.emplace_front(stk.top());
        stk.pop();
    }

    // for (auto tk : prefix) {
    //     if (tk.type == NUM) {
    //         cout << to_string(tk.num) << ' ';
    //     } else {
    //         cout << tk.op << ' ';
    //     }
    // }
    // cout << endl;

    stack<double> num;
    while (!prefix.empty()) {
        auto tk = prefix.back();
        prefix.pop_back();

        if (tk.type == NUM) {
            num.push(tk.num);
            continue;
        }

        double lhs = num.top();
        num.pop();
        double rhs = num.top();
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
            if (rhs == 0) {
                throw "error!";
            }
            ans = lhs / rhs;
            break;
        }
        num.push(ans);
    }
    return num.top();
}

int main() {
    string src;
    while (getline(cin, src)) {
        try {
            double val = solve(src);
            printf("%.2lf\n", val);
        } catch (const char *e) {
            printf("%s\n", e);
        }
    }
}
