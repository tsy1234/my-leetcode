#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    // brutal accepted
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int begin = 0;  
        int result = INT_MIN;
        for (int i = 0;i < size;i++) {
            int max = 0;
            for (int j = i;j < size;j++) {
                max += nums[j];
                if (max > result) result = max;
            }
        }
        return result;
    }

    int good(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        int ans = nums[0];
        for (int i = 0;i < size;i++) {
            sum += nums[0];
            ans = max(sum, ans);
            sum = max(sum, 0);
        }
        return ans;
    }
};

int main () {
    int arr[5] = {3, 5, -4, 1, -3};
    vector<int> test(arr, arr + 5);
    Solution s;
    cout << s.maxSubArray(test) << endl;
    return 0;
}