/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

*/

// keypoints:
// 1. binary search not functional, use corner search
// 2. how to find the right corner?
// 3. try four vertexes of matrix, those rules should be satified: 
//    --> move to horizontal direction, value monotonically change (increasing or decreasing)
//    --> move to vertical direction, value monotonically change (increasing or decreasing)
// 4. set two pointers for step 3
// 5. update those two pointers to find solution(update process is similar to binary search)


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search not functional, use corner search
        // notice left-bottom element, up is less than, right is more than
        if (matrix.empty())
            return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = m-1;
        int col = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                ++col; // move right
            } else {
                --row;
            }
        }
        
        return false;
    }
};
