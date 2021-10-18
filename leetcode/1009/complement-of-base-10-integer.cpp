// https://leetcode-cn.com/problems/complement-of-base-10-integer/

#include <cstdint>

class Solution {
  public:
    int bitwiseComplement(int n) {
        uint32_t x = n;
        if (x == 0) {
            return 1;
        }
        uint32_t y = x ^ uint32_t(0xffffffff);
        uint32_t l = 32 - __builtin_clz(x);
        uint32_t m = (uint32_t(1) << l) - 1;
        return y & m;
    }
};