class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<pair<int, int>> store;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    store.push_back({i,j});
                }
            }
        }
        for(pair<int, int> p : store){
            int r = p.first;
            int c = p.second;

            for(int j = 0; j < n; j++){
                matrix[r][j] = 0;
            }
            
            for(int i = 0; i < m; i++){
                matrix[i][c] = 0;
            }
        }
    }
};