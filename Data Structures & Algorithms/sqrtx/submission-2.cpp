class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        int l = 0, r = x;
        while(l <= r) {
            int mid = l + (r-l)/2;
            long long comp = (long long) mid*mid;

            if (comp == x) return mid;
            else if (comp < x) {
                l = mid+1;
            }
            else r = mid-1; 
        }
        return l-1;
    }
};