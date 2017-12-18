class Solution {
public:
    int titleToNumber(string s) {
        int num = 0, times = 1;
        for (int i = s.size() - 1;i >= 0;i--) {
            num += (s[i] - 'A' + 1) * times;
            times *= 26;
        }
        return num;
    }
};