class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curr = prices[0];
        for (int p : prices) {
            profit = max(profit, p-curr);
            curr = min(curr, p);
        }
        return profit;
    }
};
