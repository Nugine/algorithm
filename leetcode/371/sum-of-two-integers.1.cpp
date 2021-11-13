// https://leetcode-cn.com/problems/sum-of-two-integers/

#include <cstdint>

class Solution {
  public:
    int getSum(int a, int b) {
        uint32_t x = a, y = b;
        uint32_t p, g;
        do {
            p = x ^ y;
            g = x & y;
            x = p;
            y = g << 1;
        } while (g != 0);
        return x;
    }
};