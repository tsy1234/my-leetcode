#include <iostream>
#include <algorithms>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        vector<int> sign(length, -1);
        int pos = 0;
        while (pos < length - 1) {
            int temp = pos;
            int weight = nums[pos];
            if (weight == 0) {
                pos++;
                break;
            }
            for (int i = 0;i < weight && temp < length;i++) {
                temp++;
                if (sign[temp] == -1)
                    sign[temp] = pos;
            }
            pos++;
        }
        int result = sign[length - 1];
        while (result != -1) {
            if (result == 0) return true;
            result = sign[result];
        }
        return false;
    }

    bool better(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (int reach = 0;i < n && i <= reach;i++) {
            reach = max(i + nums[i], reach);
        }
        return i == n; 
    }
};

int main(int argc, char const *argv[]) {
	Solution s;
	int arr[5] = {3, 2, 1, 0, 4};
	vector<int> test(arr, arr + 5);
	cout << s.canJump(test) << endl;
	return 0;
}