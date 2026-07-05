/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();

        int l = 1, r = n-2;

        int peak = 0;

        while (l <= r) {
            int m = (l+r)/2;
            int left = arr.get(m-1), mid = arr.get(m), right = arr.get(m+1);
            
            if (left < mid && mid < right) l = m+1;
            else if (left > mid && mid > right) r = m-1;
            else {
                peak = m;
                break;
            }
        }


        l = 0, r = peak-1;

        while (l <= r) {
            int m = (l+r)/2;
            int mid = arr.get(m);

            if (mid < target) l = m+1;
            else if (mid > target) r = m-1;
            else return m;
        }


        l = peak, r = n-1;

        while (l <= r) {
            int m = (l+r)/2;
            int mid = arr.get(m);

            if (mid > target) l = m+1;
            else if (mid < target) r = m-1;
            else return m;
        }

        return -1;
    }
};