class Solution {
public:
    // 排序后判断数组序号是否和序号代表的内容相等
    int missingNumber(vector<int>& nums) {
        int size = nums.size(), i;
        sort(nums.begin(), nums.end());
        for (i = 0;i < size;i++) {
            if (i != nums[i]) return i;
        }
        return i;
    }
    // 异或 a ^ a = 0
    int better(vector<int>& nums) {
        int size = nums.size(), res = 0, i;
        for (i = 0;i < size;i++) {
            res ^= i ^ nums[i];
        }
        res ^= i;
        return res;
    }
};