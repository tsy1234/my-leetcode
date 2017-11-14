#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, sec = nums.size() - 1;
        for (int i = 0;i <= sec;i++) {
            while (nums[i] == 2 && i < sec) swap(nums[i], nums[sec--]);
            while (nums[i] == 0 && i > zero) swap(nums[i], nums[zero++]);
        }
    }
};

int main() {
    int a[] = {1, 0, 2};
    vector<int> arr(a, a + 3);
    Solution s;
    s.sortColors(arr);
    for (int i = 0;i < arr.size();i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}