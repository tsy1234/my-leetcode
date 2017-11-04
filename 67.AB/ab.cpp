#include <iostream>

using namespace std;

class Solution {
public:
    // not good
    string addBinary(string a, string b) {
        int al = a.size();
        int bl = b.size();
        int size = min(al, bl);
        string res;
        int carry = 0;
        int i = al - 1;
        int j = bl - 1;
        for (;i >= 0 || j >= 0;) {
            if (i >= 0 && j >= 0) {
                int an = (int)a[i--] - 48;
                int bn = (int)b[j--] - 48;
    
                if (an + bn > 1) {
                    res.insert(0, 1, '0' + carry);
                    carry = 1;
                } else {
                    int num = (an + bn + carry) / 2;
                    int no = (an + bn + carry) %2;
                    res.insert(0, 1, (char)(no + 48));
                    carry = (num == 1 ? 1 : 0);
                }
            } else if (i >= 0) {
                int an = (int)a[i--] - 48;
                int num = an + carry;
                if (num > 1) {
                    res.insert(0, 1, '0');
                    carry = 1;
                } else {
                    res.insert(0, 1, (char)(num + 48));
                    carry = 0;
                } 
            } else if (j >= 0) {
                int bn = (int)b[j--] - 48;
                int num = bn + carry;
                if (num > 1) {
                    res.insert(0, 1, '0');
                    carry = 1;
                } else {
                    res.insert(0, 1, (char)(num + 48));
                    carry = 0;
                }
            }
        }
        if (carry) res.insert(0, 1, '1');
        return res;
    }

    string good(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, c = 0;
        string s = "";
        while (i >= 0 || j >= 0 || c == 1) {
            c += (i >= 0 ? a[i--] - '0' : 0);
            c += (j >= 0 ? b[j--] - '0' : 0);
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        return s;
    }
};

int main() {
    Solution s;
    string a = "11";
    string b = "1";
    string res = s.good(a, b);
    cout << "res: " << res << endl;
    return 0;
}