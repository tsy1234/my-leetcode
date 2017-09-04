#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert (vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int num = nums[mid];
            if (num < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main (int argc, char const *argv[]) {
    vector<int> a(5, 3);
    Solution s;
    int res = s.searchInsert(a, 5);
    cout << res << endl;
    return 0;
}