class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return min(count(cost, 0, dp), count(cost, 1, dp));
    }

private:
    int count(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size()) return 0;

        if (dp[i] == -1) {
            dp[i] = cost[i] + min(count(cost, i+1, dp), count(cost, i+2, dp));
        }

        return dp[i];
    }
};
