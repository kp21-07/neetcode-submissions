class Solution {
    vector<pair<int, int>> DIRS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int max_area = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    int area = 0;
                    q.push({i, j});
                    visited[i][j] = 1;
                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        area++;
            
                        for (auto& [dx, dy] : DIRS) {
                            int nx = x+dx, ny = y+dy;
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                            if (grid[nx][ny] == 1 && visited[nx][ny] == 0) {
                                q.push({nx, ny});
                                visited[nx][ny] = 1;
                            }
                        }
                    }
                    max_area = max(max_area, area);
                }
            }
        }

        return max_area;
    }
};
