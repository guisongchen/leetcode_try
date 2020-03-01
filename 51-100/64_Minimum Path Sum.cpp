/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

// keypoints:
// 1. use dynamic planning
// 2. handle corner case like: i = 0, j = 0
// 3. we can create new array dp or use original grid array

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // notice one thing, from top left to bottom right
        // the minmize path must be combination of move right and move down
        
        // corner case
        if (grid.size() == 0)
            return 0;
        
        int row = grid.size();
        int col = grid[0].size();
        
        // since padding help most at the first row and first column
        // if we can handle them seperatly, we can save the padding space
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // leave [0][0] untouched
                if (i == 0 && j == 0)
                    continue;
                
                // handle the first row, add left
                // i-1 and j-1 are safe since we handle [0][0] early
                if (i == 0)
                    grid[i][j] += grid[i][j-1];
                else if (j == 0) // handle first column, add up
                    grid[i][j] += grid[i-1][j];
                else
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[row-1][col-1];
    }
};
