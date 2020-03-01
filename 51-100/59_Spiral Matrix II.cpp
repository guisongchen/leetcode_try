/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

// keypoints:
// 1. use the same trick as we did in Spiral Matrix
// 2. using four pointer to restrict travese boundaries

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // corner case
        if (n == 1)
            return  vector<vector<int>>{{1}};
        
        int left = 0, right = n-1, up = 0, down = n-1;
        int cnt = 1;
        vector<vector<int>> ret(n, vector<int>(n, 0));
        while (left <= right && up <= down) {
            for (int i = left; i <= right; i++) {
                ret[up][i] = cnt++;
            }
            
            for (int j = up+1; j <= down; j++) {
                ret[j][right] = cnt++;
            }
            
            if (left < right && up < down) {
                
                for (int i = right-1; i >= left; i--) {
                    ret[down][i] = cnt++;
                }
                
                for (int j = down-1; j >= up+1; j--) {
                    ret[j][left] = cnt++;
                }
            }
            
            left++;
            right--;
            up++;
            down--;
        }
        
        return ret;
    }
};
