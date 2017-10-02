#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector< vector<int> >& matrix) {
        vector<int> result;
        int rowsMin = columnsMin = 0;
        int rows, columns;
        rows = matrix.size() - 1;
        columns = matrix[0].size() - 1;
        int total = (rows + 1) * (columns + 1);
        while (total) {
            for (int i = rowsMin;i < rows;i++) {
                result.push();
            }
        }
    }
};

int main () {

    return 0;
}