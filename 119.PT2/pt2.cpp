class Solution {
public:
    /*
    使用一个数组last来记录上一行的数
    now使用last来生成 然后将now赋给last
    下一个循环
    */
    vector<int> getRow(int rowIndex) {
        rowIndex = rowIndex + 1;
        vector<int> last, now;
        for (int i = 0;i < rowIndex;i++) {
            now.resize(i + 1);
            now[0] = now[i] = 1;
            for (int j = 1;j < i;j++) {
                now[j] = last[j] + last[j - 1];
            }
            last = now;
        }
        return now;
    }
    // nice
    vector<int> good(int rowIndex) {
        vector<int> r(rowIndex + 1, 0);
        r[0] = 1;
        for (int i = 1;i < rowIndex + 1;i++) {
            for (int j = i;j >= 1;j++) {
                r[j] += r[j - 1];
            }
        }
        return r;
    }
};