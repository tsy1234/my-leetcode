class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size(), index = 0, indexAfter = 0;
        while (index < len) {
            int count = 0;
            char current = chars[index];
            while (index < len && (chars[index] == current)) {
                index++;
                count++;
            }
            chars[indexAfter] = current;
            indexAfter++;
            if (count > 1) {
                stringstream ss;
                ss << count;
                string str = ss.str();
                for (int i = 0;i < str.size();i++) {
                    chars[indexAfter] = str[i];
                    indexAfter++;
                }
            }
        }
        return indexAfter;
    }
};