class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        int len = s.size();
        for (int i = 0;i < len;i++) {
            map[s[i]]++;
        }
        for (int i = 0;i < len;i++) {
            if (map[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};