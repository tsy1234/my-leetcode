#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > permuteUnique(vector<int>& nums) {
        vector< vector<int> > result;
        sort(nums.begin(), nums.end());
        permutation(nums, 0, result);
        return result;
    }

    void permutation (vector<int> nums, int begin, vector< vector<int> >& result) {
        if (begin >= nums.size()) {
            result.push_back(nums);
            return;
        }

        vector<int> container;
        for (int i = begin;i < nums.size();i++) {
            if (i != begin && (find(container.begin(), container.end(), nums[i]) != container.end())) continue;
            container.push_back(nums[i]);
            swap(nums[i], nums[begin]);
            permutation(nums, begin + 1, result);
            swap(nums[i], nums[begin]);
        }
    }
};

int main () {
    Solution s;
    int arr[3] = {1, 2, 3};
    vector<int> test(arr, arr + sizeof(arr) / sizeof(int));
    vector< vector<int> > res = s.permuteUnique(test);
    int size = res.size();
    for (int i = 0;i < size;i++) {
        for (int j = 0;j < 3;j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    return 0;
}