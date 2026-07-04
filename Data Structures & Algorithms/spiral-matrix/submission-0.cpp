class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m*n, 0);

        int i = 0, j = 0;
        int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
        int direction = RIGHT;

        int UP_WALL = 0;
        int RIGHT_WALL = n;
        int DOWN_WALL = m;
        int LEFT_WALL = -1;
        int ct = 0;

        while (ct != m*n){
            if (direction == RIGHT){
                while (j < RIGHT_WALL){
                    ans[ct] = matrix[i][j];
                    j++;
                    ct++;
                }
                i++;
                j--;
                RIGHT_WALL--;
                direction = DOWN;
            } else if (direction == DOWN){
                while (i < DOWN_WALL){
                    ans[ct] = matrix[i][j];
                    i++;
                    ct++;
                }
                i--;
                j--;
                DOWN_WALL--;
                direction = LEFT;
            } else if (direction == LEFT){
                while (j > LEFT_WALL){
                    ans[ct] = matrix[i][j];
                    j--;
                    ct++;
                }
                i--;
                j++;
                LEFT_WALL++;
                direction = UP;
            } else {
                while (i > UP_WALL){
                    ans[ct] = matrix[i][j];
                    i--;
                    ct++;
                }
                i++;
                j++;
                UP_WALL++;
                direction = RIGHT;
            }
        }
        
        return ans; 
    }
};