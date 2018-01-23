#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> num1 = { 8, 4, 2, 1 };
        vector<int> num2 = { 32, 16, 8, 4, 2, 1 };
        stringstream ss;
        vector<string> res;
        for (int i = 0;i <= num;i++) {
            vector<int> list1 = generateDigits(num1, i);
            vector<int> list2 = generateDigits(num2, num - i);
            for (int m = 0;m < list1.size();m++) {
                if (list1[m] >= 12) continue;
                for (int n = 0;n < list2.size();n++) {
                    if (list2[n] >= 60) continue;
                    ss << list1[m];
                    string hour = ss.str();
                    ss.str("");
                    ss << list2[n];
                    string minute = ss.str();
                    ss.str("");
                    res.push_back(hour + ":" + (list2[n] < 10 ? ("0" + minute) : minute));
                }
            }
        }
        return res;
    }

    vector<int> generateDigits(vector<int> nums, int count) {
        vector<int> res;
        generateDigitsHelper(nums, 0, 0, count, res);
        return res;
    }

    void generateDigitsHelper(vector<int> nums, int pos, int sum, int count, vector<int>& res) {
        if (count == 0) {
            res.push_back(sum);
            return;
        }
        for (int i = pos;i < nums.size();i++) {
            generateDigitsHelper(nums, i + 1, sum + nums[i], count - 1, res);
        }
    }
};

class another {
private:
    vector<int> hour = {1, 2, 4, 8}, minute = {1, 2, 4, 8, 16, 32};
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        helper(res, make_pair(0, 0), num, 0);
        return res;
    }
    
    void helper(vector<string>& res, pair<int, int> time, int num, int start_point) {
        if (num == 0) {
            res.push_back(to_string(time.first) +  (time.second < 10 ?  ":0" : ":") + to_string(time.second));
            return;
        }
        for (int i = start_point; i < hour.size() + minute.size(); i++)
            if (i < hour.size()) {    
                time.first += hour[i];
                if (time.first < 12)     helper(res, time, num - 1, i + 1);     // "hour" should be less than 12.
                time.first -= hour[i];
            } else {     
                time.second += minute[i - hour.size()];
                if (time.second < 60)    helper(res, time, num - 1, i + 1);     // "minute" should be less than 60.
                time.second -= minute[i - hour.size()];
            }
    }
}


// // test
// int main() {
//     Solution s;
//     vector<string> res = s.readBinaryWatch(5);
//     for (int i = 0;i < res.size();i++) {
//         cout << res[i] << endl;
//     }
//     return 0;
// }