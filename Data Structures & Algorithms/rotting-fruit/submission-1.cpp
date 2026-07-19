class Solution {
    vector<pair<int, int>> DIRS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        queue<pair<int, int>> q;

        int fresh = 0;
        int minutes = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        while (fresh > 0 && !q.empty()) {
            int len = q.size();
            
            for (int i = 0; i < len; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& [dx, dy] : DIRS) {
                    int nx = x+dx, ny = y+dy;

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        continue;
                    }

                    if (grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }

            }
            minutes++;
        }

        return fresh > 0 ? -1 : minutes;
    }
};
