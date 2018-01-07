class Solution {
public:
    bool isAnagram(string s, string t) {
        int hmS[26] = {0};

        if (s.size() != t.size()) return false;

        for (int i = 0;i < s.size();i++) {
            hmS[s[i] - 97]++;
            hmS[t[i] - 97]--;
        }

        for (int i = 0;i < 26;i++) {
            if (hmS[i] != 0) return false;
        }
        return true;
    }

    bool stl(string s, string t) {
        if (s.size() != t.size()) return false;
        int n = s.length();
        unordered_map<char, int> counts;
        for (int i = 0;i < n;i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }
        for (int i = 0;i < counts.size();i++) {
            if (counts[i]) return false;
        }
        return true;
    }
};