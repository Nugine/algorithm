// https://leetcode-cn.com/problems/number-complement/
// https://leetcode-cn.com/problems/complement-of-base-10-integer/

#include <cstdint>

class Solution {
  public:
    int findComplement(int num) {
        uint32_t x = num;
        uint32_t y = x ^ uint32_t(0xffffffff);
        uint32_t l = 32 - __builtin_clz(x);
        uint32_t m = (uint32_t(1) << l) - 1;
        return y & m;
    }
};