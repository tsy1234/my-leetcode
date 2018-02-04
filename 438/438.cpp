class Solution {
public:
    // 遍历字符串s，对每个字符后面的总共p的长度的字符进行统计，如果是p的变形词，添加当前位置到数组
    vector<int> findAnagrams(string s, string p) {
        int indiceLen = p.size(), totalLen = s.size();
        vector<int> res;
        if (indiceLen > totalLen) return 0;
        int c[26] = { 0 };
        for (int i = 0;i < indiceLen;i++) c[p[i] - 'a']++;
        int start = 0;
        for (;start < totalLen - indiceLen + 1;start++) {
            int temp[26];
            copy(begin(c), end(c), begin(temp));
            int i = 0;
            for (;i < indiceLen;i++) {
                if (temp[s[start + i] - 'a'] <= 0) {
                    break;
                }
                temp[s[start + i] - 'a']--;
            }
            if (i >= indiceLen) {
                res.push_back(start);
            }
        }
        return res;
    }

    // 滑动窗口算法，每次将后一个字符加入到窗口内，将窗口开头的字符从窗口排除
    vector<int> better(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        vector<int> res;
        if (pLen > sLen) return res;
        vector<int> pv(26, 0), sv(26, 0);
        for (int i = 0;i < pLen;i++) {
            sv[s[i] - 'a']++;
            pv[p[i] - 'a']++;
        }
        if (sv == pv) res.push_back(0);
        for (int i = pLen;i < sLen;i++) {
            sv[s[i] - 'a']++;
            sv[s[i - pLen] - 'a']--;
            if (sv == pv) res.push_back(i - pLen + 1);
        }
        return res;
    }
};