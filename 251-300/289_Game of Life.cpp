/*

According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

*/



class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // since all cell update simultaneously, but neighors need original status to update
        // tricky part is we need to keep prev status without copy input matrix
        // use FSM (0: died, 1: live)
        // code     before  after
        // 0:       0   ->  0
        // 1:       1   ->  1
        // 2:       1   ->  0
        // 3:       0   ->  1
        // when we check status, we need to know prev status info
        // when code is 1 or 2, means prev status is live, code % 2 get the final status(0 or 1)
        
        if (board.empty())
            return;
        
        int m = board.size();
        int n = board[0].size();
        int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
        int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = j + dx[k];
                    int y = i + dy[k];
                    
                    // check around
                    if (x >= 0 && x < n && y >= 0 && y < m && 
                        (board[y][x] == 1 || board[y][x] == 2))  // prev status is live
                        ++cnt;
                }
                
                if (board[i][j] && (cnt > 3 || cnt < 2))
                    board[i][j] = 2; // 1->0, live to die
                else if (!board[i][j] && cnt == 3)
                    board[i][j] = 3; // 0->1, die to live
            }
        }
        
        // solve code, trans 2 and 3 into 0 and 1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};
