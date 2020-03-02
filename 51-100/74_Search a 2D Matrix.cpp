/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

// keypoints:
// 1. use binary search
// 2. use double pointers
// 3. chose i = 0 and j = col as pointer, because i = 0 point to min of row, j = col point to max of row 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // NULL case
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        // binary search, first locate row, then search in row
        // OR we can just consider matrix as one-dim array, which needs to handle index
        // 
        // OR we can use double pointer
        
        int i = 0;
        int j = col-1;
        
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) { // move to next row
                i++;
            } else { // move to left
                j--;
            }
        }
        
        return false;
    }
};
