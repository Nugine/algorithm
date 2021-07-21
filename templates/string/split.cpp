#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

int main() {
    auto parts = split("a b c d", " ");
    for (auto &p : parts) {
        cout << p << endl;
    }
    return 0;
}