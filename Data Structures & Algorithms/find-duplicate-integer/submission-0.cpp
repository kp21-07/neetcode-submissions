class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> count(nums.size(), 0);

        for (int n : nums) {
            count[n-1]++;
            if (count[n-1] == 2) return n;
        }

        return -1;
    }
};
