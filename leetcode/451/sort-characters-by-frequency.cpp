// https://leetcode-cn.com/problems/sort-characters-by-frequency/

#include <algorithm>
#include <cstdint>
#include <string>
using namespace std;

class Solution {
  public:
    string frequencySort(string s) {
        pair<uint32_t, uint8_t> bucket[256];
        for (uint8_t i = 0;; ++i) {
            bucket[i] = make_pair(0, i);
            if (i == 255) {
                break;
            }
        }
        for (auto c : s) {
            bucket[uint8_t(c)].first += 1;
        }
        sort(bucket, bucket + 256, greater<pair<uint32_t, uint8_t>>());
        int top = 0;
        for (auto &pr : bucket) {
            while (pr.first--) {
                s[top++] = pr.second;
            }
        }
        return s;
    }
};