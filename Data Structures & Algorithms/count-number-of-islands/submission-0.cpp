class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int i = 0, j = 0;
        int count = 0;
        vector<int> visited(n * m, 0);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                visited[i + n * j] = 0;
            }
        }

        i = 0;
        j = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (visited[i * m + j] != 0)
                    continue;
                if (grid[i][j] != '1')
                    continue;
                count++;
                queue<pair<int, int>> q;
                q.push({i, j});

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    visited[x * m + y] = 1;
                    for (auto d : dir) {
                        int nx = d.first + x;
                        int ny = d.second + y;
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if (visited[nx * m + ny] != 0)
                            continue;
                        if (grid[nx][ny] != '1')
                            continue;
                        visited[nx * m + ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return count;
    }
};