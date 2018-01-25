class Solution {
public:
    // my code
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for (int i = 0;i < s.size();i++) {
            map[s[i]]++;
        }

        unordered_map<char,int>::iterator it = map.begin();
        bool hasOdd = false;
        int res = 0;
        while (it != map.end()) {
            if (it->second % 2 == 0) {
                res += it->second;
            } else {
                res += it->second - 1;
                hasOdd = true;
            }
            it++;
        }
        if (hasOdd) {
            res += 1;
        }
        return res;
    }

    int better(string s) {
        int odd = 0;
        for (char c = 'A';c <= 'z';c++) {
            odd += count(s.begin(), s.end(), c) & 1;
        }
        return s.size() - odd + (odd > 0);
    }
};