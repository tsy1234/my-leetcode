#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int p;
        if (n < 0) {
            p = -n;
            x = 1 / x;
        } else {
            p = n;
        }
        while (p) {
            if (abs(p) == 1) ans *= x;
            x *= x;
            p >>= 1;
        }
        return ans;
    }
};

int main () {
    Solution s;
    cout << s.myPow(2, 2) << endl;
    return 0;
}