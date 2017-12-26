class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0;i < 32;i++, n >>= 1) {
            if (n & 1) count++;
        }
        return count;
    }
    // too slow
    int two(uint32_t n) {
        int count = 0;
        while (n > 0) {
            if (n % 2 == 1) count++;
            n /= 2;
        }
        return count;
    }
};