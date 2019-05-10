#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int minSwapsCouples(vector<int> &row) {
        int len = row.size();

        vector<int> pos(len);
        int i;
        for (i = 0; i < len; ++i) {
            pos[row[i]] = i;
        }
        int ans = 0;
        for (i = 0; i < len; i += 2) {
            if ((row[i] ^ 1) == row[i + 1]) {
                continue;
            }
            int idx = pos[row[i] ^ 1];
            pos[row[i + 1]] = idx;
            pos[row[idx]] = i + 1;
            swap(row[i + 1], row[idx]);
            ++ans;
        }
        return ans;
    }
};