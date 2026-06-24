class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[write-1]) {
                nums[write++] = nums[i];
            }
        }
        return write;
    }
};