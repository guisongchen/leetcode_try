/*

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

*/


// keypoints: translate problem into: find O on the border and O connect with it
// 1. find 'O' on the border, and its connecting, mark them as '#'
// 2. flipping all remaining 'O' to 'X', which means they are surrounded by "#"
// 3. set '#' to "O"
// 4. use four direction vector to do dfs


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // of course use dfs here
        // keypoint:
        // 1. find 'O' on the border, and its connecting, mark them as '#'
        // 2. flipping all remaining 'O' to 'X', which means they are surrounded by "#"
        // 3. set '#' to "O"
        
        // corner case
        if (board.empty())
            return;
        
        for (int i = 0, n = board.size(); i < n; i++) {
            for (int j = 0, m = board[0].size(); j < m; j++) {
                if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if (board[i][j] == 'O') {
                        board[i][j] = '#';
                        dfs(board, i, j);
                    }
                }
            }
        }
        

        for (int i = 0, n = board.size(); i < n; i++) {
            for (int j = 0, m = board[0].size(); j < m; j++) {
                char& ch = board[i][j];
                if (ch == 'O') {
                    ch = 'X';
                } else if (ch == '#') {
                    ch = 'O';
                }
            }
        }
        
    }
    
    void dfs(vector<vector<char>>& board, int i , int j) {
        
        for (int k = 0; k < 4; k++) {
            
            int next_i = i + direction[k][0];
            int next_j = j + direction[k][1];
            
            if ((next_i >= 0 && next_i < board.size()) &&
                (next_j >= 0 && next_j < board[0].size())) {
                if (board[next_i][next_j] == 'O') {
                    board[next_i][next_j] = '#';
                    dfs(board, next_i, next_j);
                }
            }
        }
    }
    
    // left, right, up, down
    int direction[4][2]{0, -1, 0, 1, -1, 0, 1, 0};

};
