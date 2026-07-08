class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return check(nums, 0, dp);
    }

private:
    int check(vector<int>&nums, int i, vector<int>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] == -1) {
            dp[i] = max(check(nums, i+1, dp), nums[i]+check(nums, i+2, dp));
        }
        return dp[i];
    }
};
