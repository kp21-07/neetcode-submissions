class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
        }

        vector<vector<int>> freq(nums.size()+1);

        for (const auto& [n, c] : mp) {
            freq[c].push_back(n);
        }

        vector<int> ans;
        for (int i = freq.size()-1; i > 00; i--) {
            for (int n : freq[i]) {
                ans.push_back(n);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};