class Solution {
public:
    bool canWinNim(int n) {
        // 假设A先手，B后手
        // 只要最后轮到A时，还剩4个，A就输了，所以当石头数量为4的倍数时，
        // 每一轮A+B可以一直为4，最后剩下的一定是4,所以不为4有赢的机会
        return (n % 4 != 0);
    }
};