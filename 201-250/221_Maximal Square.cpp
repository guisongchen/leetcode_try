/*

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

*/

// solution 1: brutal force
// 1. apply sliding window on rows, from 0~n, 1~n, 2~n,....n~n
// 2. since row range is given by step 1, iteration from col 0~m to find max square
//    --> col length must equal to row length
//    --> row range changes, so col range changes, iteration each grid to find maximum value
//    --> using histogram to find contiguous square(which all grid should be '1')



// solution 2: dynamic planning
// 1. defination of dp[i][j], max square from [0][0] to [i][j]
// 2. transform equation: dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
//    --> why min?
//    --> only dp[i-1][j], dp[i-1][j-1], dp[i][j-1] all equal to 1, dp[i][j] will plus one
//    --> if one of them is '0', won't form a square
// 3. border condition: i = 0, j = 0, dp[i][j] = grid[i][j]

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // corner case
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> dp(row, vector<int>(col, 0));
        
        int ret = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = matrix[i][j] - '0';           
                else if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                }
                
                ret = max(ret, dp[i][j]);
            }
        }
        
        return ret*ret;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // corner case
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int ret = 0;
        
        // start from [0,0]
        for (int i = 0; i < row; ++i) {
            // cut branches
            if (row-i+1 <= ret)
                    continue;
            
            // traverse matrix from start position
            // since we iterate by col, count '1' of each col
            //  1 1 0
            //  1 1 0   <-- histogram
            //  1 1 1  
            //  3 3 1 <-- sum of each col
            vector<int> sum(col, 0);  // number of 1 in each col
            for (int j = i; j < row; ++j) {
                for (int k = 0; k < col; ++k) {
                    if (matrix[j][k] == '1')
                        ++sum[k];  // col length add 1, if sum[k] = row length
                }
                
                // row length: j-i+1, start from row i, ending at row j
                ret = max(ret, countArea(sum, j-i+1));
            }
        }
        
        return ret*ret;
    }
    
    int countArea(vector<int>& sum, int len) {
        if (len > sum.size()) // not square, row length > col length
            return 0;
        
        // col length >= row length now
        
        int cnt = 0;
        for (auto it : sum) {
            if (it != len)
                cnt = 0; // not full, reset cnt to keep contiguous
            else
                ++cnt;
            
            if (cnt == len)
                return len;
        }
        
        return 0;
    }
};
