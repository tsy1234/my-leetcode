class Solution {
public:
    // 两个字符串相同位置的字符一一对应
    bool isIsomorphic(string s, string t) {
        char mapS[128] = { 0 };
        char mapT[128] = { 0 };
        int len = s.size();
        for (int i = 0;i < len;i++) {
            if (mapS[s[i]] != mapT[t[i]]) return false;
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }
        return true;
    }
};