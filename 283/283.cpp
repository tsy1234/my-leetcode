class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0;i < size;i++) {
            if (nums[i] == 0) {
                for (int j = i;j < nums.size() - 1;j++) {
                    nums[j] = nums[j + 1];
                }
                i--;
                nums[nums.size() - 1] = 0;
                size--;
            }
        }
    }

    void better(vector<int>& nums) {
        int j = 0, size = nums.size();
        for (int i = 0;i < size;i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < size;j++) {
            nums[j] = 0;
        }
    }
};