#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector<int> > rec(m, vector<int>(n));
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (i == 0 || j== 0) rec[i][j] = 1;
                else rec[i][j] = rec[i - 1][j] + rec[i][j - 1];
            }
        }
        return rec[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    int res = s.uniquePaths(3, 2);
    cout << res << endl;
    return 0;
}