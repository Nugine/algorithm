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

template <typename T> T solve(const string &src, string &dst);

int main() {
    // freopen("in", "r", stdin);

    string src;
    string dst;

    int t = 0;
    while (getline(cin, src)) {
        ll ans = solve<ll>(src, dst);

        cout << "Case " << (++t) << ":\n";
        cout << dst << endl;
        cout << ans << endl;
    }
    return 0;
}

template <typename T> struct Token {
    int type;
    union {
        T num;
        char op;
    };

    Token(T num) : num(num) { type = 1; }
    Token(char op) : op(op) { type = 2; }
};

unordered_map<char, int> table = {{'+', 1}, {'-', 1}, {'*', 2}};
unordered_set<char> ops = {'(', ')', '+', '-', '*'};

template <typename T> T solve(const string &src, string &dst) {
    deque<Token<T>> infix;
    int len = src.size();
    for (int i = 0; i < len; ++i) {
        if (isdigit(src[i])) {
            T t = 0;
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

    stack<char> stk;
    deque<Token<T>> prefix;
    while (!infix.empty()) {
        auto tk = infix.back();
        infix.pop_back();

        if (tk.type == 1) {
            prefix.push_front(tk);
        } else {
            if (stk.empty()) {
                stk.push(tk.op);
            } else {
                if (tk.op == ')') {
                    stk.push(tk.op);
                } else if (tk.op == '(') {
                    while (!stk.empty() && stk.top() != ')') {
                        prefix.emplace_front(stk.top());
                        stk.pop();
                    }
                    if (stk.top() == ')') {
                        stk.pop();
                    }
                } else {
                    if (stk.top() == ')') {
                        stk.push(tk.op);
                    } else {
                        if (table[stk.top()] <= table[tk.op]) {
                            stk.push(tk.op);
                        } else {
                            while (!stk.empty() && stk.top() != ')' &&
                                   table[stk.top()] > table[tk.op]) {
                                prefix.emplace_front(stk.top());
                                stk.pop();
                            }
                            stk.push(tk.op);
                        }
                    }
                }
            }
        }
    }
    while (!stk.empty()) {
        prefix.emplace_front(stk.top());
        stk.pop();
    }

    dst.clear();
    for (auto tk : prefix) {
        string s;
        if (tk.type == 1) {
            s = to_string(tk.num);
        } else {
            s = tk.op;
        }
        if (!dst.empty()) {
            dst += ' ';
        }
        dst += s;
    }

    stack<T> num;
    while (!prefix.empty()) {
        auto tk = prefix.back();
        prefix.pop_back();

        if (tk.type == 1) {
            num.push(tk.num);
        } else {
            T lhs = num.top();
            num.pop();
            T rhs = num.top();
            num.pop();

            T ans;
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
            }
            num.push(ans);
        }
    }
    return num.top();
}