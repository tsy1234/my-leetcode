#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,tmp,'/')) {
            if (tmp == "" or tmp == ".") continue;
            if (tmp == ".." and !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        for (int i = 0;i < stk.size();i++) {
            res += "/" + stk[i];
        }
        return res.empty() ? "/" : res;
    }
};

int main() {
    Solution s;
    string path = "/a/./b/../../c/";
    string res = s.simplifyPath(path);
    cout << res << endl;
    return 0;
}