/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // NULL case
        if (obstacleGrid.size() == 0)
            return 0;
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        // since we only move right or down
        // pos(i, j) is decided by left and up status
        // transform equation:
        // pos[i][j] = pos[i-1][j] + pos[i][j-1]
        // we use i-1 and j-1 to solve i,j, add padding 1X1 to avoid handling boundary
        //  * * * *
        //  * 0 0 0
        //  * 0 1 0
        //  * 0 0 1
        
        // padding pos[0][0] = 0, start point is pos[1][1] = pos[0][1] + pos[1][0]
        // important thing is decide pos[0][1] or pos[1][0]
        // first, check if we can stand pos[1][1], aka check obstacleGrid[0][0]
        // also if finsih point is obstacle, we can't reach
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[row-1][col-1] == 1)
            return 0;
        
        vector<vector<long>> pos(row+1, vector<long>(col+1, 0));
        
        // now we are sure to stand on pos[1][1], check pos[0][1] or pos[1][0]
        // since they are standable pad we add, we can just set one of them to '1'
        pos[0][1] = 1;
        
        // check pos after padding, size(row+1, col+1)
        for (int i = 1; i < row+1; i++) {
            for (int j = 1; j < col+1; j++) {
                // only at this situation, we can't move to pos[i][j]
                //  1 0
                //  0 0
                if (obstacleGrid[i-1][j-1] == 1)
                    continue;
                
                pos[i][j] = pos[i-1][j] + pos[i][j-1];
            }
        }
        
        return pos[row][col];
    }
};
