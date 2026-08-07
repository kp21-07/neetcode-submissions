class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);
        return max(nums[0],
               max(helper(nums1), helper(nums2)));
    }

private:
    int helper(vector<int>& nums) {
        int next = 0, next2 = 0;
        for (int num : nums) {
            int curr = max(next2 + num, next);
            next2 = next;
            next = curr;
        }
        return next;
    }
};