class Solution {
    vector<pair<int, int>> DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    void solve(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1)
                    if (grid[i][j] == 'O') q.push({i,j});
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (grid[x][y] == 'O') {
                grid[x][y] = 'T';
                
                for (auto& [dx,dy] : DIRS) {
                    int nx = x+dx, ny = y+dy;
                    if (nx < 0 || nx >= ROWS || ny < 0 || ny >= COLS) {
                        continue;
                    }
                    q.push({nx,ny});
                }
            }
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 'T') grid[i][j] = 'O';
                else if (grid[i][j] == 'O') grid[i][j] = 'X';
            }
        }
        
    }
};
