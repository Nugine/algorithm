#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, string> table = {
    {0, "zero"},        {1, "one"},         {2, "two"},
    {3, "three"},       {4, "four"},        {5, "five"},
    {6, "six"},         {7, "seven"},       {8, "eight"},
    {9, "nine"},        {10, "ten"},        {11, "eleven"},
    {12, "twelve"},     {13, "thirteen"},   {14, "fourteen"},
    {15, "fifteen"},    {16, "sixteen"},    {17, "seventeen"},
    {18, "eighteen"},   {19, "nineteen"},   {20, "twenty"},
    {21, "twenty one"}, {22, "twenty two"}, {23, "twenty three"},
    {30, "thirty"},     {40, "forty"},      {50, "fifty"},
};

string &resolve(int num) {
    if (table.count(num)) {
        return table[num];
    }
    int t1 = (num / 10) * 10;
    int t2 = num % 10;
    string ans = {table[t1]};
    ans += ' ';
    ans += table[t2];
    table[num] = ans;
    return table[num];
}

void solve(int h, int m) {
    string ans;
    if (m == 0) {
        ans += resolve(h);
        ans += " o'clock";
    } else {
        ans += resolve(h);
        ans += ' ';
        ans += resolve(m);
    }
    cout << ans << endl;
}

int main() {
    int h, m;
    while (cin >> h >> m) {
        solve(h, m);
    }
    return 0;
}