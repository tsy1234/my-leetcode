class Solution {
public:
    void rotateOne(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        for (int i = 0;i < k;i++) {
            int temp = nums[n - k + i];
            for (int j = n - k + i;j > i;j--) {
                nums[j] = nums[j - 1];
            }
            nums[i] = temp;
        }
    }
    void rotateTwo(vector<int>& nums, int k) {
        k = k % nums.size();
        for (int i = 0;i < k;i++) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    }
    void rotateThr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> numsCopy(n);
        for (int i = 0;i < n;i++) {
            numsCopy[i] = nums[i];
        }
        for (int i = 0;i < n;i++) {
            nums[(i + k) % n] = numsCopy[i];
        }
    }
};