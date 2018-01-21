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
    // faster
    int funny(string s) {
        int len = s.size();
        if (len == 0) {
            return -1;
        }
        int countNum[256] = {0};
        int slow = 0, fast = 1;
        countNum[s[slow]]++;
        while (fast < len) {
            countNum[s[fast]]++;
            
            while (slow < len && countNum[s[slow]] > 1) {
                slow++;
            }
            if (slow >= len) { // no unique char
                return -1;
            }
            fast++;
        }
        return slow;
    }
};