class Solution {
public:
    int arrangeCoins(int n) {
        int rows = 1, res = 0;
        while (n >= rows) {
            res++;
            n -= rows;
            rows++;
        }
        return res;
    }

    // 1+2+3+…+x = n
    // -> (1+x)x/2 = n
    // -> x^2+x = 2n
    // -> x^2+x+1/4 = 2n +1/4
    // -> (x+1/2)^2 = 2n +1/4
    // -> (x+0.5) = sqrt(2n+0.25)
    // -> x = -0.5 + sqrt(2n+0.25)
    int better(int n) {
        return floor(-0.5 + sqrt((double)2 * n + 0.25));
    }
};