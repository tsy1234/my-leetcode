class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int pa[26] {};
        unordered_map<string, int> wr;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word;in >> word;i++) {
            if (i == n || pa[pattern[i] - 'a'] != wr[word])
                return false;
            pa[pattern[i] - 'a'] = wr[word] = i + 1; 
        }
        return i == n;
    }
};