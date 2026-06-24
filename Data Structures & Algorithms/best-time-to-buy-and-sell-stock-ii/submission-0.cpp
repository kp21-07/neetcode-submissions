class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i-1]) {
                profit += prices[i-1] - curMin;
                curMin = prices[i];
                cout << curMin << " " << i << endl;
            }
        }
        profit += prices[prices.size()-1]-curMin;
        return profit;
    }
};