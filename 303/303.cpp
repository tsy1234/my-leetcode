class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        for (int i = 0, len = nums.size();i < len;i++) {
            acc.push_back(sum);
            sum += nums[i];
        }
        acc.push_back(sum);
    }
    
    int sumRange(int i, int j) {
        return acc[j + 1] - acc[i];
    }
private:
    vector<int> acc;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */