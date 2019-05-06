#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;
typedef long long ll;

void solve();
int main() {
    int N;
    cin >> N;
    while (N--) {
        solve();
    }
    return 0;
}

unordered_map<string, double> table = {
    {"UTC", +0},     {"GMT", +0},  {"BST", +1},   {"IST", +1},   {"WET", +0},
    {"WEST", +1},    {"CET", +1},  {"CEST", +2},  {"EET", +2},   {"EEST", +3},
    {"MSK", +3},     {"MSD", +4},  {"AST", -4},   {"ADT", -3},   {"NST", -3.5},
    {"NDT", -2.5},   {"EST", -5},  {"EDT", -4},   {"CST", -6},   {"CDT", -5},
    {"MST", -7},     {"MDT", -6},  {"PST", -8},   {"PDT", -7},   {"HST", -10},
    {"AKST", -9},    {"AKDT", -8}, {"AEST", +10}, {"AEDT", +11}, {"ACST", +9.5},
    {"ACDT", +10.5}, {"AWST", +8},

};

void solve() {
    string tm, apm, zone1, zone2;
    int hh, mm;

    cin >> tm;
    if (tm == "noon") {
        hh = 12;
        mm = 0;
    } else if (tm == "midnight") {
        hh = mm = 0;
    } else {
        istringstream iss(tm);
        char c;
        iss >> hh >> c >> mm;

        cin >> apm;
        if (apm == "p.m.") {
            hh %= 12;
            hh += 12;
        }
    }
    cin >> zone1 >> zone2;

    int time1 = hh * 60 + mm;
    int time0 = time1 - table[zone1] * 60;
    int time2 = time0 + table[zone2] * 60;
    time2 = (time2 + 24 * 60) % (24 * 60);

    hh = time2 / 60;
    mm = time2 % 60;

    if (hh == 0 && mm == 0) {
        cout << "midnight" << endl;
    } else if (hh == 12 && mm == 0) {
        cout << "noon" << endl;
    } else {
        if (hh < 12) {
            hh = (hh == 0) ? 12 : hh;
            cout << hh << ":" << mm << " a.m." << endl;
        } else {
            hh -= 12;
            hh = (hh == 0) ? 12 : hh;
            cout << hh << ":" << mm << " p.m." << endl;
        }
    }
}