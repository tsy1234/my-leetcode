class Solution {
public:
    bool isPowerOfTwo(int n) {
        int rem = 0;
        if (n <= 0) return false;
        while (n >= 2) {
            rem = n % 2;
            if (rem != 0) return false;
            n /= 2;
        }
        return true;
    }
    // 如果是2的幂，那么二进制只有最高位为1,其他位为0,与n-1进行与操作，结果为0
    bool better(int n) {
        if (n <= 0) return false;
        return !(n & (n - 1));
    }
};