#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define rng(i, s, e) for ((i) = (s); (i) < (e); ++(i))
#define desc(i, s, e) for ((i) = (s); (i) >= (e); --(i))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
// #define eprintf(...)

vector<string> split(const string &s, const string &sep) {
    vector<string> parts;
    size_t start = 0;
    for (;;) {
        size_t end = s.find(sep, start);
        parts.push_back(s.substr(start, end - start));
        if (end == s.npos) {
            break;
        }
        start = end + sep.length();
    }
    return parts;
}

struct Sol {
    struct Arg {
        bool is_parsed;
        bool has_value;
        string value;
    };
    map<char, Arg> arg_map;

    void parse_fmt(const string &fmt) {
        int len = fmt.length();
        int i;
        rng(i, 0, len) {
            char c = fmt[i];
            struct Arg arg;
            if ('a' <= c && c <= 'z') {
                arg.has_value = (i + 1 < len && fmt[i + 1] == ':');
                arg_map[c] = arg;
            }
        }
    }

    void run() {
        string s;
        cin >> s;
        parse_fmt(s);

        int n;
        cin >> n;

        getline(cin, s);

        int i;
        asc(i, 1, n) {
            getline(cin, s);
            cout << "Case " << i << ": ";
            parse_line(s);
            show_ans();
        }
    }

    void parse_line(const string &line) {
        for (auto &pr : arg_map) {
            pr.second.is_parsed = false;
        }

        auto parts = split(line, " ");
        int i;
        rng(i, 1, int(parts.size())) {
            const auto &part = parts[i];
            assert(part.length() > 0);
            if (part[0] != '-' || part.length() != 2) {
                break;
            }
            if (arg_map.count(part[1]) == 0) {
                break;
            }
            auto &arg = arg_map[part[1]];
            if (arg.has_value) {
                if (i + 1 >= int(parts.size())) {
                    break;
                }
                const auto &next_part = parts[i + 1];
                assert(next_part.length() > 0);
                arg.value = next_part;
                ++i;
            }
            arg.is_parsed = true;
        }
    }

    void show_ans() {
        bool is_first = true;
        for (const auto &pr : arg_map) {
            const auto &arg = pr.second;
            if (!arg.is_parsed) {
                continue;
            }
            if (is_first) {
                is_first = false;
            } else {
                cout << ' ';
            }
            cout << '-' << pr.first;
            if (arg.has_value) {
                cout << ' ' << arg.value;
            }
        }
        cout << '\n';
    }
};

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    static Sol sol;
    sol.run();
    return 0;
}