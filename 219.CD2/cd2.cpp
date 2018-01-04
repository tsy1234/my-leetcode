class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        int size = nums.size();
        if (k <= 0) return false;
        if (k >= size - 1) k = size - 1;
        for (int i = 0;i < size;i++) {
            if (i > k) set.erase(nums[i - k - 1]);
            if (set.find(nums[i]) != set.end()) return true;
            set.insert(nums[i]);
        }
        return false;
    }
};