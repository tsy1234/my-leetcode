#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > result;
        permutation(nums, 0, result);
        return result;
    }

    void permutation (vector<int> nums, int begin, vector< vector<int> >& result) {
        if (begin >= nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = begin;i < nums.size();i++) {
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
    cout << s.permute(test).size() << endl;
    return 0;
}