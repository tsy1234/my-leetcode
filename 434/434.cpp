class Solution {
public:
    int countSegments(string s) {
        string::iterator begin = s.begin();
        string::iterator end = s.end();
        bool hasSpace = true;
        int num = 0;
        while (begin != end) {
            if (*begin == ' ') {
                hasSpace = true;
            } else {
                if (hasSpace) {
                    num++;
                    hasSpace = false;
                }
            }
            begin++;
        }
        return num;
    }

    int another(string s) {
        s.push_back(' ');
        int res = 0, size = s.size();
        for (int i = 0;i < size;i++) {
            if (s[i] == ' ' && s[i - 1] != ' ') res++;
        }
        return res;
    }
};