/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // NULL case
        if (matrix.size() == 0)
            return;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        /*
        vector<bool> markRows(row, false);
        vector<bool> markCols(col, false);
        */
        
        // we can use first row and first col to record zero marks of other cols and rows
        // use two flag to mark first row and first col
        bool firstRowFlag = false;
        bool firstColFlag = false;
        
        for (int j = 0; j < col; j++) {
            if (matrix[0][j] == 0) {
                firstRowFlag = true;
                break;
            }
        }
        
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                firstColFlag = true;
                break;
            }
        }
        
        // use first row and col to record marks
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {                
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // set
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        // handle first row and col
        if (firstRowFlag) {
            for (int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if (firstColFlag) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }        
        
    }
};
