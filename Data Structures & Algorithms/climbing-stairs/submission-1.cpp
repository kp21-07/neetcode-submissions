class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return count(n, dp);
    }

private:
    int count(int n, vector<int>& dp) {
        if (n <= 1) return 1;
        else {
            if (dp[n] == -1) {
                dp[n] = count(n-1, dp) + count(n-2, dp);
            }
            return dp[n];
        }
    }
};
