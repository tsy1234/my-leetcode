#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        string index(n, '0');
        int f = 1;
        for (int i = 1;i <= n;i++) {
            f *= i;
            index[i - 1] += i;
        }
        k--;

        int i = 0;
        int si = n - 1;
        while (i < n) {
            f /= n - i;
            int j = k / f;
            s[i] = index[i + j];
            for (int a = i + j;a > i;a--) {
                index[a] = index[a - 1];
            }
            k = k % f;
            i++;
        }
        return s;
    }
};

int main() {
    Solution s;
    string c = s.getPermutation(5, 3);
    cout << c << endl;
    return 0;
}