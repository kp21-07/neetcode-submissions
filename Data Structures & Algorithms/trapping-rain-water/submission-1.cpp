class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int water = 0;
        int l_max = height[l];
        int r_max = height[r];
        while (l < r) {
            if (l_max < r_max) {
                l++;
                l_max = max(l_max, height[l]);
                water += l_max - height[l];
            }
            else {
                r--;
                r_max = max(r_max, height[r]);
                water += r_max - height[r];
            }
        }
        return water;
    }
};