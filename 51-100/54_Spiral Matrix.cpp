/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

// keypoints:
// 1. assign boundaries to traverse
//    --- use four indexs: left, right, up, down;
// 2. careful about "=", make sure no overlap exist

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // null case
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return vector<int>{};
        
        // define return value
        vector<int> ret;
        const int row = matrix.size();
        const int col = matrix[0].size();
        /*
           i j----->
           |
           |
           
           left(up)---------------------->right(up)
           left(up+1)                     right(up+1)
           ^                                |
           |                                |
           |                                |
           left(down-1)                     |
           left(down)<----(right-1)(down) right(down)
        */
        int up = 0, down = row-1, left = 0, right = col-1;
        
        while (up <= down && left <= right) {
            // left(up) -> right(up)
            for (int j = left; j <= right; j++)
                ret.push_back(matrix[up][j]);
            // right(up) -> right(down)
            for (int i = up+1; i <= down; i++)
                ret.push_back(matrix[i][right]);
            
            // element in core should only print once
            if (left < right && up < down) {            
                // right(down) -> left(down)
                for (int j = right-1; j >= left; j--)
                    ret.push_back(matrix[down][j]);
                // left(down) -> left(up)
                for (int i = down-1; i >= up+1; i--)
                    ret.push_back(matrix[i][left]);
            }
            
            // finish one circle, update info for next circle, until no circle exist
            up++;
            down--;
            left++;
            right--;
        }
        
        return ret;

    }
};
