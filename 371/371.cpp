class Solution {
public:
    // 用与运算并左移一位得到进位，用异或运算得到不带进位的和，当进位为0,运算结束
    int getSum(int a, int b) {
        // 进位
        int carry = 0;
        while (b != 0) {
            carry = a & b;
            // 不带进位的和赋给a
            a = a ^ b;
            // 得到的进位赋予b
            b = carry << 1;
        }
        return a;
    }

    // recursive
    int recur(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
};