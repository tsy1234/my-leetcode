#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (n--) {
            int temp = b;
            b += a;
            a = temp;
        }
        return a;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(3) << endl;
}