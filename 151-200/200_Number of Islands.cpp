/*

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

*/

// solution 1
// 1. using dfs and visit maxtrix
// 2. instead using visit matrix, we turn visited grid into '0'

// solution 2
// 1. using bfs
// 2. using queue to keep un-visited grid
// 3. new id of [i,j] = i*cols + j = i*m +j

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // dfs of course, edges maybe tricky
        if (grid.empty() || grid[0].empty())
            return 0;
         
        int cnt = 0;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
        // instead of using visit matrix, we turn visited grid into 0
        
        for (int i = 0, n = grid.size(); i < n; ++i) {
            for (int j = 0, m = grid[0].size(); j < m; ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    
                    queue<int> q{{i*m + j}};
                    
                    while (!q.empty()) {
                        int cur = q.front();
                        q.pop();
                        
                        int cur_i = cur / m;
                        int cur_j = cur % m;
                        
                        for (int k = 0; k < 4; ++k) {
                            int ni = cur_i + dir[k][0];
                            int nj = cur_j + dir[k][1];
                            
                            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1') {
                                grid[ni][nj] = '0';
                                q.push(ni*m + nj);
                            }
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};





class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // dfs of course, edges maybe tricky
        if (grid.empty() || grid[0].empty())
            return 0;
         
        int cnt = 0;
        
        // instead of using visit matrix, we turn visited grid into 0
        for (int i = 0, n = grid.size(); i < n; ++i) {
            for (int j = 0, m = grid[0].size(); j < m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++cnt;
                }
            }
        }
        
        return cnt;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        // mark visited grid
        grid[i][j] = '0';
        
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};
