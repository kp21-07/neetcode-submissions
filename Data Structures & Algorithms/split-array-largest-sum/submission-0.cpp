class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;
        for (int n : nums) {
            l = max(l, n);
            r += n;
        }

        int res = r;

        while (l <= r) {
            int mid = (l+r)/2;
            bool can_split = true;
            int subarrays = 1;
            int curr_sum = 0;
            for (int n : nums) {
                if (curr_sum + n > mid) {
                    subarrays++;
                    if (subarrays > k) {
                        can_split = false;
                        break;
                    }
                    curr_sum = 0;
                }
                curr_sum += n;
            }

            if (can_split) {
                res = mid;
                r = mid-1;
            }
            else l = mid+1;
        }

        return res;
    }
};