class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size(), index = 1;
        for (int i = len - 1;i > 0;i--) {
            if (nums[i - 1] != nums[i]) {
                index++;
            }
            if (index == 3) {
                return nums[i - 1];
            }
        }
        if (index < 3) {
            return nums[len - 1];
        }
    }
    // 通过set来筛选出相同的值 set内部自动排序
    int better(vector<int>& nums) {
        set<int> top3;
        for (int num : nums) {
            top3.insert(num);
            if (top3.size() > 3) {
                top3.erase(top3.begin());
            }
        }
        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
    }

    int another(vector<int>& nums) {
        int first = INT_MIN;
        int second = INT_MIN:
        int third = INT_MIN;
        for (int num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }
        return third == INT_MIN ? first : third;
    }
};