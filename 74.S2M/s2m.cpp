#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int t = m * n - 1;
        int start = 0;
        while (start <= t) {
            int mid = (start + t) / 2;
            int row = mid / n, col = mid % n;
            int temp = matrix[row][col];
            if (temp == target) return true;
            if (temp > target) t = mid - 1;
            else if (temp < target) start = mid + 1;
        }
        return false;
    }
};

int main() {
    vector< vector<int> > vv(3);	
	for(int i=0;i<3;i++) 
        vv[i].resize(4);

    vv[0][0] = 1;
    vv[0][1] = 3;
    vv[0][2] = 5;
    vv[0][3] = 7;
    vv[1][0] = 10;
    vv[1][1] = 11;
    vv[1][2] = 16;
    vv[1][3] = 20;
    vv[2][0] = 23;
    vv[2][1] = 30;
    vv[2][2] = 34;
    vv[2][3] = 50;
    
    Solution s;

    bool res = s.searchMatrix(vv, 12);
    cout << res << endl;
    return 0;
}