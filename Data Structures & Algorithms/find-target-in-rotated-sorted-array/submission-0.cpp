class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums.back()) l = mid + 1;
            else r = mid;
        }

        int rot = l;
        l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int real = (mid + rot) % n;

            if (nums[real] == target)
                return real;

            if (nums[real] < target) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
};