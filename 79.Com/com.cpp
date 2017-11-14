#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        vector< vector<int> > res;
        vector<int> p(k, 0);
        int i = 0;
        while (i >= 0) {
            p[i]++;
            if (p[i] > n) i--;
            else if (i == k - 1) res.push_back(p);
            else {
                ++i;
                p[i] = p[i - 1];
            }
        }
        return res;
    }

    vector< vector<int> > back(int n, int k) {
        v.resize(k);
        backTra(1, n, k);
        return r;
    }

private:
    vector<int> v;
    vector< vector<int> > r;
    void backTra(int start, int n, int k) {
        while (start <= n) {
            v[v.size() - k] = start++;
            if (k > 1) backTra(start, n, k - 1);
            else r.push_back(v);
                
        }
    }
};

int main() {
    Solution s;
    vector< vector<int> > res;
    res = s.back(4, 2);
    for (int i = 0;i < res.size();i++) {
        for (int j = 0;j < 2;j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}