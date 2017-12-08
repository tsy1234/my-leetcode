class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, len = prices.size();
        for (int i = 0;i < len - 1;i++) {
            int pre = prices[i];
            for (int j = i + 1;j < len;j++) {
                int sub = prices[j] - prices[i];
                if (sub > profit)
                    profit = sub;
            }
        }
        return profit;
    }

    int good(vector<int>& prices) {
        int len = prices.size();
        int minPrice = INT_MAX;
        int maxPro = 0;
        for (int i = 0;i < len;i++) {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};