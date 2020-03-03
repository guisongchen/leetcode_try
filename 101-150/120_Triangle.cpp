/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // keypoint: minimum and adjacent
        // think different, from down to top, left to right, 2 steps
        // 1. find min from cur idx and after idx(this is adjacent in row)
        // 2. plus same idx of prev row(this is adjacent in column)
        // dp[i][j] = min(dp[i][j], dp[i][j+1]) + triangle[i][j]
        // since last row has the longest length, use it as dp length, which gives:
        // dp[j] = min(dp[j], dp[j+1]) + triangle[i][j]
        
        if (triangle.size() == 0)
            return 0;
        
        vector<int> dp(triangle.back());
        
        // we copy the last row, so start from last 2nd row
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        
        // from down to top, row 0 is last row, so min-path is on idx 0
        return dp[0];
    }
};
