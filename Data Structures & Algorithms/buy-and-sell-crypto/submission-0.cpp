class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curr = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            profit = max(profit, prices[i]-curr);
            curr = min(curr, prices[i]);
        }
        return profit;
    }
};
