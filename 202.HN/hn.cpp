class Solution {
public:
    int next(int num) {
        int res = 0, tmp;
        while (num != 0) {
            tmp = num % 10;
            res += tmp * tmp;
            num/= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        int pre = n, back = next(n);
        while (pre != back) {
            pre = next(pre);
            back = next(next(back));
        }
        return pre == 1;
    }
};