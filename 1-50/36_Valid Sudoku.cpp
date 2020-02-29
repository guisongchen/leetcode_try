/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/

// keypoints:
// 1. how to represent those characters in board?
//    -> use vector<vector<bool>> is a choose, 
//    -> better choose is use short and each bit of short represent element in row or col or box
// 2. how to check current element exist in col or row or box ?
//    -> use '&'
// 3. how to update state of each col or row or box after traverse current element?
//    -> use '|'

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    // since row < 9, use a short int digit to represent a row
    // each bit of digit represent cols of same row
    // so does col and cell
    vector<short> row(9, 0);
    vector<short> col(9, 0);
    vector<short> cell(9, 0);
    
        for (int i =  0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.')
                    continue;
                
                // set corresponding bit 1
                short cur = 1 << (board[i][j] - '0');
                
                // check
                if (row[i] & cur || col[j] & cur || cell[3*(i/3)+j/3] & cur)
                    return false;
                
                // update
                row[i] |= cur;
                col[j] |= cur;
                cell[3*(i/3)+j/3] |= cur;
            }
        }
        
        return true;
        
    }
};
