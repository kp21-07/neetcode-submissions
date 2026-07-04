class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rows;
        vector<int> columns;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }

        for(int r : rows){
            for(int j = 0; j < n; j++){
                matrix[r][j] = 0;
            }
        }

        for(int c : columns){
            for(int i = 0; i < m; i++){
                matrix[i][c] = 0;
            }
        }
    }
};