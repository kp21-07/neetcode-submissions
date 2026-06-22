class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool has_zero = false;
        bool has_2_zeros = false;
        int res = 1;
        for (int n : nums) {
            if (n == 0) {
                if (has_zero) has_2_zeros = true;
                has_zero = true;
                continue;
            }
            res *= n;
        }

        vector<int> output(nums.size(), 0);

        if (has_2_zeros) return output;

        if (has_zero) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) output[i] = res;
                else output[i] = 0; 
            }

            return output;
        }

        for (int i = 0; i < nums.size(); i++) {
            output[i] = res/nums[i];
        }

        return output;
    }
};
