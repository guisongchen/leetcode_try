/*

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // keypoints: init as all '1', updates elements except beginning and end
        if (numRows < 1)
            return vector<vector<int>>{};
        
        vector<vector<int>> ret;
        
        for (int i = 1; i <= numRows; i++) {
            vector<int> cur(i, 1);
            if (i <= 2) {
                ret.push_back(cur);
            } else {
                for (int j = 1; j < i-1; j++)
                    cur[j] = ret.back()[j] + ret.back()[j-1];
                ret.push_back(cur);
            }
        }
        
        return ret;
    }
};
