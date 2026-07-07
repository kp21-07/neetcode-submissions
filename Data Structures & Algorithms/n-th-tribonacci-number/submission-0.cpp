class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return check(n, dp);
    }

private:
    int check(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (n < 3) return 1;

        if (dp[n] == -1) {
            dp[n] = check(n-1, dp) + check(n-2, dp) + check(n-3, dp);
        }

        return dp[n];
    }
};