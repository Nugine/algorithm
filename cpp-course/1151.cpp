#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define rd(x) scanf("%d", &(x))
#define rd2(x, y) scanf("%d %d", &(x), &(y))
#define rd3(x, y, z) scanf("%d %d %d", &(x), &(y), &(z))
#define asc(i, s, e) for ((i) = (s); (i) <= (e); ++(i))
#define pdln(x) printf("%d\n", (x))

void solve();
int main() {
    int T;
    rd(T);
    while (T--) {
        solve();
    }
    return 0;
}

unordered_map<string, int> haab_table = {
    {"pop", 0},  {"no", 1},     {"zip", 2},    {"zotz", 3},    {"tzec", 4},
    {"xul", 5},  {"yoxkin", 6}, {"mol", 7},    {"chen", 8},    {"yax", 9},
    {"zac", 10}, {"ceh", 11},   {"mac", 12},   {"kankin", 13}, {"muan", 14},
    {"pax", 15}, {"koyab", 16}, {"cumhu", 17}, {"uayet", 18},
};

unordered_map<int, string> tzolkin_table = {
    {0, "imix"},   {1, "ik"},     {2, "akbal"},  {3, "kan"},    {4, "chicchan"},
    {5, "cimi"},   {6, "manik"},  {7, "lamat"},  {8, "muluk"},  {9, "ok"},
    {10, "chuen"}, {11, "eb"},    {12, "ben"},   {13, "ix"},    {14, "mem"},
    {15, "cib"},   {16, "caban"}, {17, "eznab"}, {18, "canac"}, {19, "ahau"},
};

void solve() {
    int dd;
    string mm;
    int yy;
    cin >> dd >> mm >> yy;

    int days = dd + haab_table[mm] * 20 + yy * 365;

    yy = days / 260;
    mm = tzolkin_table[(days % 260) % 20];
    dd = (days % 260) % 13 + 1;
    cout << dd << " " << mm << " " << yy << endl;
}
