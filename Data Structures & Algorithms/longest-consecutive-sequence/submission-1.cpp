class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> s;
        for (int num : nums) s.insert(num);

        int maxi = 0;

        for (auto num : s) {
            if (s.find(num-1) != s.end()) continue;
            int count = 0;
            while(s.find(num++) != s.end()) count++;
            maxi = max(maxi, count);
        }

        return maxi;
    }
};