#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector< vector<int> > rec(m, vector<int>(n));
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (obstacleGrid[i][j] == 1) {
                    rec[i][j] = 0;
                    continue;
                }
                if (i != 0 && j != 0) rec[i][j] = rec[i - 1][j] + rec[i][j - 1];
                else if (i == 0 && j != 0) rec[i][j] = rec[i][j - 1];
                else if (j == 0 && i != 0) rec[i][j] = rec[i - 1][j];
                else rec[i][j] = 1;
            }
        }
        return rec[m - 1][n - 1];
    }
};