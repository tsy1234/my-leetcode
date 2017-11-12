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
    int v1[] = {1, 3, 5, 7};
    int v2[] = {10, 11, 16, 20};
    int v3[] = {23, 30, 34, 50};
    vector< vector<int> > vv(3);	
	for(int i=0;i<3;i++) 
        vv[i].resize(4);
    
    vv[0].insert(vv[0].begin(), v1, v1 + 4);
    vv[1].insert(vv[1].begin(), v2, v2 + 4);
    vv[2].insert(vv[2].begin(), v3, v3 + 4);
    
    Solution s;

    bool res = s.searchMatrix(vv, 11);
    cout << res << endl;
    return 0;
}