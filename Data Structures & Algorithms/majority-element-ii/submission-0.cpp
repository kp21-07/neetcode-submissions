class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i : nums) freq[i]++;

        vector<int> res;
        for (const auto& [n, c] : freq) {
            if (c > nums.size()/3) res.push_back(n);
        }

        return res;
    }
};