class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n-1;
        int mid;
        while(l <= r) {
            mid = (l+r)/2;
            if (matrix[mid][0] > target) r = mid-1;
            else if (matrix[mid][0] < target && matrix[mid][m-1] > target) break;
            else l = mid+1;
        }
        mid = (l+r)/2;
        l = 0, r = m-1;
        while (l <= r) {
            int mid2 = (l+r)/2;
            if (matrix[mid][mid2] == target) return true;
            else if (matrix[mid][mid2] > target) r = mid2-1;
            else l = mid2+1;
        }
        return false;
    }
};