class Solution {
public:
    string reverseString(string s) {
        string res = "";
        for (int i = s.size() - 1;i >= 0;i--) {
            res += s[i];
        }
        return res;
    }

    string better() {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
        return res;
    }
};