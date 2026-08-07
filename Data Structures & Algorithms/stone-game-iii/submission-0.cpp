class Solution {
    int MIN = -50000001;

public:
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, MIN);

        auto min_max = [&] (this auto& min_max, int i) -> int {
            if (i == n) return 0;
            
            int res = dp[i];
            if (res != MIN) return res;

            int sum = 0;
            for (int j = 1; j <= 3 && i + j <= n; j++) {
                sum += nums[i+j-1];
                res = max(res, sum-min_max(i+j));
            }

            dp[i] = res;
            return res;
        };

        int d = min_max(0);

        if (d == 0) return "Tie";
        else if (d > 0) return "Alice";
        else return "Bob";
    }
};