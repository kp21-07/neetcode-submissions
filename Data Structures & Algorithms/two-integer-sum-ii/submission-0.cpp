class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (indices.contains(target - nums[i])) {
                return {indices[target - nums[i]]+1, i+1};
            }
            indices[nums[i]] = i;
        }

        return {-1, -1};
    }
};