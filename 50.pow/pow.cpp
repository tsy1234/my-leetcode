#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long p = n;
        if (n < 0) {
            p = -p;
            cout << p << endl;
            x = 1 / x;
        } else {
            p = n;
        }
        while (p) {
            if (p & 1) ans *= x;
            x *= x;
            p >>= 1;
            // cout << p << endl;
        }
        return ans;
    }
};

int main () {
    Solution s;
    // cout << s.myPow(1.00000, -2147483648) << endl;
    int end = 2147483648;
    cout << end << endl;
    return 0;
}