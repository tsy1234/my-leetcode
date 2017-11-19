#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int time = 0, len = nums.size(), i = 0, del = 0;
        if (len == 0) return 0;
        int cur = nums[0];
        while (i < len - del) {
            if (nums[i] != cur) {
                time = 0;
                cur = nums[i];
                continue;
            }
            time++;
            if (time >= 3) {
                for (int j = i + 1;j < len;j++) {
                    nums[j - 1] = nums[j];
                }
                i--; 
                del++;
            }
            i++;
        }
        return len - del;
    }

    int easy(vector<int>& nums) {
        int i = 0;
        for (int j = 0;j < nums.size();j++) {
            if (i < 2 || nums[j] > nums[i - 2]) nums[i++] = nums[j];
        }
        return i;
    }
};

int main() {
    Solution s;
    int a[] = {1, 1, 1, 1, 3, 3};
    vector<int> arr(a, a + 6);
    int res = s.easy(arr);
    cout << res << endl;
    for (int i = 0;i < arr.size();i++) {
        cout << arr[i] << endl;
    }
    return 0;
}