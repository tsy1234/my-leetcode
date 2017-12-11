class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0;i < nums.size() - 1;i += 2) {
            if (nums[i] != nums[i+1])
                return nums[i];
        }
        return nums[nums.size() - 1];
    }
    // 一个数异或自己为0 遍历数组异或 剩下的就是单个数字的值
    int good(vector<int>& nums) {
        for (int i = 1;i < nums.size();i++) {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};