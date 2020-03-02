/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

// keypoints:
// 1. use dfs and visited matrix to mark used elements, use direction matrix to control traverse direction
// 2. notice: element first marked as used, 
//            if we checking all combinations and not return, we can mark it as un-used at last! 
//            which means marked used at the beginning of loop and recover it at the ending of loop

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // step 1: find first char of input word
        // step 1: dfs from 1st char of word
        
        if (board.empty())
            return false;
        
        int row = board.size();
        int col = board[0].size();
        
        // to save space, we can mark used by change board element to special sign 
        // vector<vector<bool>> used(row, vector<bool>(col, false));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                
                if (board[i][j] == word[0]) {         
                    if (dfs(board, word, i, j, 1))
                        return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int cnt) {
        
        // only all characters match we can mark it used
        // since we don't know all match results now
        // we suppose this true, if not, we retrive it back to false at last 
        
        // to save space, we can mark used by change board element to special sign 
        //used[i][j] = true;
        char temp = board[i][j];
        board[i][j] = '/';

        // since we confirm all chars, return
        if (cnt == word.size())
            return true;
        
        for (int d = 0; d < 4; d++) {
            int next_i = i + dir[d][0];
            int next_j = j + dir[d][1];
            
            if (next_i < 0 || next_i >= board.size() ||
                next_j < 0 || next_j >= board[0].size())
                continue;
            
            if (board[next_i][next_j] == '/' || board[next_i][next_j] != word[cnt])
                continue;
            
            if (dfs(board, word, next_i, next_j, cnt+1))
                return true;
        }
        
        // only after failed four directions then return false
        //used[i][j] = false; //retrive back status for next recursive
        board[i][j] = temp;
        return false;
    }
    
    // left right up down
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
};
