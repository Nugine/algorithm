#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int n;
int s0=0,s1=0;

void solve(int &ansA,int &ansB){
    if(s0==s1){
        ansA=ansB=n;
        return;
    }

    // ansB
    ansB = min(s0,s1) *2;

    // ansA


}

int main() {
    int i, s1, s0, n, l, p, r, ans;
    char ch;
    cin >> n;
    getchar();
    getline(cin, str);

    for(auto &c:str) {
        if (c == '0')
            s0++;
        else{
            s1++;
        }
        c-='0';
    }

    int ansA,ansB;
    solve(ansA,ansB);



    if (s0 == s1)
        cout << n << " " << n << endl;
    else {
        if (s1 < s0)
            ch = '1';
        else
            ch = '0';
        for (i = 0; i < n; i++) {
            if (str[i] == ch) {
                p = i;
                r = 1;
                l = 1;
                break;
            }
        }
        ans = 0;
        for (i = p + 1; i < n; i++) {
            if (str[i] == ch) {
                if (i - p - 2 <= r) {
                    r = r - i + p + 2;
                    l = l + i - p + r;
                    p = i;
                } else {
                    if (l > ans)
                        ans = l;
                    l = 1;
                    r = 1;
                    p = i;
                }
            }
        }
        if (l > ans)
            ans = l;
        cout << ans << " ";
        if (s1 > s0)
            cout << s0 * 2 << endl;
        else
            cout << s1 * 2 << endl;
    }
    return 0;
}
