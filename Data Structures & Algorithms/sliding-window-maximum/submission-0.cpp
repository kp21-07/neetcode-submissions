class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        pair<int, int> curr_max = {-10001, -1};
        for (int i = 0; i < k; i++) {
            if (nums[i] > curr_max.first) {
                curr_max.first = nums[i];
                curr_max.second = i;
            }
        }

        vector<int> res(nums.size()-k+1);
        res[0] = curr_max.first;

        for (int i = k; i < nums.size(); i++) {
            if (curr_max.second == i-k) {
                curr_max = {nums[i - k + 1], i - k + 1};
                for (int j = i - k + 1; j <= i; j++) {
                    if (nums[j] >= curr_max.first) {
                        curr_max.first = nums[j];
                        curr_max.second = j;
                    }
                }
            }
            else if (nums[i] >= curr_max.first) {
                curr_max.first = nums[i];
                curr_max.second = i;
            }
            
            res[i-k+1] = curr_max.first;
        }

        return res;
    }
};
