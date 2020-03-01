/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/

// keypoints:
// 1. use dfs;
// 2. use memo to record success times at each grid

class Solution {
public:
    int uniquePaths(int m, int n) {
        // dyamic planning
        // corner case
        if (m < 1 || n < 1)
            return 0;

        // keep successed cnt that use current grid
        // if we stand on this grid, we use the cnt instead of doing search again
        vector<vector<int>> reachCnt(n, vector<int>(m, 0));
        
        // finish pos is on row: n-1 and col: m-1
        // we start from (0,0), move one step we do row-- or col--, threshold is 0
        return dfs(m-1, n-1, reachCnt);
    }
    
private:
    int dfs(int col, int row, vector<vector<int>>& reachCnt) {
        
        if (col < 0 || row < 0) { // over boundary
            return 0;
        } else if (col == 0 && row == 0) { // successed
            return 1;
        } else if (reachCnt[row][col]) { // use record cnt instead of search again
            return reachCnt[row][col];
        } else { // do a new search, move right or move down
            reachCnt[row][col] = dfs(col-1, row, reachCnt) + dfs(col, row-1, reachCnt);
            return reachCnt[row][col];
        }

    }
    
};
