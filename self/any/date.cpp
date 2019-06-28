#include <iostream>
using namespace std;

class Date {
  public:
    static const int table[2][13];
    int year, month, day;
    bool is_leap;

    Date(int yyyy, int mm, int dd) : year(yyyy), month(mm), day(dd) {
        is_leap = is_leap_year(yyyy);
    }

    static bool is_leap_year(int year) {
        return (year % 100 != 0 && year % 4 == 0) || year % 400 == 0;
    }

    Date &operator++() {
        const int max_day = table[int(is_leap)][month];
        if (++day > max_day) {
            day = 1;
        } else {
            return *this;
        }
        if (++month > 12) {
            month = 1;
        } else {
            return *this;
        }
        ++year;
        is_leap = is_leap_year(year);
        return *this;
    }

    Date &operator--() {
        if (--day > 0) {
            return *this;
        }
        if (--month > 0) {
            const int max_day = table[int(is_leap)][month];
            day = max_day;
            return *this;
        }
        --year;
        is_leap = is_leap_year(year);
        month = 12;
        day = 31;
        return *this;
    }
};

const int Date::table[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main() {
    Date date = {2019, 1, 1};
    int i = 400;
    while (i--) {
        ++date;
        printf("%04d-%02d-%02d\n", date.year, date.month, date.day);
    }
    i = 400;
    while (i--) {
        --date;
    }
    printf("\n%04d-%02d-%02d\n", date.year, date.month, date.day);
    return 0;
}
