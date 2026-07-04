class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};