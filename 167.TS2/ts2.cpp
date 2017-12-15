class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int hi = numbers.size() - 1, lo = 0;
        vector<int> res;
        while (numbers[lo] + numbers[hi] != target) {
            if (numbers[lo] + numbers[hi] < target) {
                lo++;
            } else {
                hi--;
            }
        }
        return vector<int>({lo + 1, hi + 1});
    }
};