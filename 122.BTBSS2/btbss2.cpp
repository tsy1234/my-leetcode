class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size(), maxPro = 0;
        for (int i = 0;i < len - 1;i++) {
            int pro = prices[i + 1] - prices[i];
            if (pro > 0) {
                maxPro += pro;
            }
        }
        return maxPro;
    }
};