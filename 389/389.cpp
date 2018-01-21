class Solution {
public:
    // use map
    char findTheDifference(string s, string t) {
        unordered_map<char, int> map1, map2;
        int sLen = s.size();
        for (int i = 0;i < sLen + 1;i++) {
            if (i != sLen) {
                map1[s[i]]++;
                map2[t[i]]++;
            } else {
                map2[t[i]]++;
            }
        }
        for (int i = 0;i < sLen + 1;i++) {
            if (map1[t[i]] != map2[t[i]]) {
                return t[i];
            }
        }
    }

    // use XOR
    char better(string s, string t) {
        char r = 0;
        int sLen = s.size(), tLen = t.size();
        for (int i = 0;i < sLen;i++) {
            r ^= s[i];
        }
        for (int i = 0;i < tLen;i++) {
            r ^= t[i];
        }
        return r;
    }
};