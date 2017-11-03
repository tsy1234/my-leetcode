// time limit exceeded
class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {
        this->res = INT_MAX;
        this->m = grid.size();
        this->n = grid[0].size();
        pathWeight(grid, 0, 0, 0);
        return this->res;
    }
private:
    int res;
    int m;
    int n;
    void pathWeight(vector< vector<int> >& grid, int weight, int row, int col) {
        if (row == m - 1 && col == n-1) {
            int w = weight + grid[row][col];
            if (w < res) res = w;
            return;
        }

        if (row < m - 1) pathWeight(grid, weight + grid[row][col], row + 1, col);
        if (col < n - 1) pathWeight(grid, weight + grid[row][col], row, col + 1);
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);

        for (int i = 1;i < m;i++) {
            pre[i] = pre[i - 1] + grid[i][0];
        }
        for (int i = 1;i < n;i++) {
            cur[0] = pre[0] + grid[0][i];
            for (int j = 1;j < m;j++) {
                cur[j] = min(cur[j - 1], pre[j]) + grid[j][i];
            }
            swap(pre, cur);
        }
        return pre[m - 1];
    }
};