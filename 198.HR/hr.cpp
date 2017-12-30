class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size(), last = 0, now = 0;
        for (int i = 0;i < len;i++) {
            int temp = last;
            last = now;
            now = max(temp + nums[i], now);
        }
        return now;
    }

    int rob2(vector<int>& nums) {
        int len = nums.size(), inc = 0, exc = 0;
        for (int i = 0;i < len;i++) {
            int tmp = inc;
            inc = exc + nums[i];
            exc = max(tmp, exc);
        }
        return max(inc, exc);
    }
};