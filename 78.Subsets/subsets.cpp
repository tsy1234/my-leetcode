#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        this->num = nums.size();
        this->r.push_back(this->v);
        for (int i = 1;i <= this->num;i++) {
            this->v.resize(i);
            back(0, i, nums, i);
        }   
        return r;
    }

    void back(int start, int len, vector<int>& nums, int k) {
        while (start < this->num) {
            this->v[len - k] = nums[start++];
            if (k > 1) back(start, len, nums, k - 1);
            else this->r.push_back(v);
        }
    }
private:
    vector< vector<int> > r;
    vector<int> v;
    int num;
};

int main() {
    Solution s;
    int a[] = {1, 2, 3};
    vector<int> input(a, a + 3);
    vector< vector<int> > res = s.subsets(input);
    cout << res.size() << endl;
    return 0;
}