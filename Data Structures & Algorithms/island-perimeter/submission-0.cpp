class Solution {
    int n, m;
    vector<vector<int>> visited;
    vector<vector<int>> grid;

    int dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return 1;

        if (visited[i][j] == 1) return 0;

        visited[i][j] = 1;

        return dfs(i, j+1) + dfs(i+1, j) + dfs(i, j-1) + dfs(i-1, j); 
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();

        visited = vector<vector<int>>(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return dfs(i, j);
            }
        } 
    }
};