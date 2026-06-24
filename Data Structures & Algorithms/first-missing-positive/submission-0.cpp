class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        for (int i : nums) {
            if (i > 0 && i < n+1) dp[i-1]++;
        }

        for (int i = 0; i < n; i++) {
            if (dp[i] == 0) return i+1;
        }

        return n+1;
    }
};