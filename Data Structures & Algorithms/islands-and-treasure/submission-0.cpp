class Solution {
    vector<pair<int, int>> DIRS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto& [dx, dy] : DIRS) {
                int nx = x+dx, ny = y+dy;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                if (grid[nx][ny] != INT_MAX) continue;
                
                grid[nx][ny] = grid[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
};