class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size(), n2 = nums2.size();

        int low = 0, high = n1;

        while (low <= high) {
            int cut1 = (low+high)/2;
            int cut2 = (n1+n2+1)/2 - cut1;

            int max_left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int min_right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            
            int max_left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int min_right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (max_left1 <= min_right2 && max_left2 <= min_right1) {
                if ((n1+n2)%2 != 0) return max(max_left1, max_left2);
                else {
                    return (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0;
                }
            }
            else if (max_left1 > min_right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
        return -1.0;
    }
};
