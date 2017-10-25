#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
        vector< vector<int> > res(n, vector<int>(n));
        int i = 1, num = n * n;
        int rowMin = 0, colMin = 0;
        int columns = n;
        int rows = n; 
        while (i <= num) {
            for (int k = colMin;k < columns;k++) {
                res[rowMin][k] = i;
                i++;
            }
        
            rowMin++;

            for (int k = rowMin;k < rows;k++) {
                res[k][columns - 1] = i;
                i++;
            }
            
            columns--;
            
            for (int k = columns - 1;k >= colMin;k--) {
                res[rows - 1][k] = i;
                i++;
            }
            
            rows--;

            for (int k = rows - 1;k >= rowMin;k--) {
                res[k][colMin] = i;
                i++;
            }
            colMin++;
        }
        return res;
    }
};

int main() {
    Solution s;
    int n = 4;
    vector< vector<int> > res = s.generateMatrix(n);
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
