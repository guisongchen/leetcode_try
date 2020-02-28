/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

class Solution {
public:
    string convert(string s, int numRows) {
        // corner case
        if (numRows == 1)
            return s;
        
        // keypoint:
        // 1. use string to store each row, use vector to store string
        // 2. use % to decide when to flip direction
        // 3. notice givern numRows start from 1 and vector index from 0
        
        vector<string> result(numRows);
        int curRow = 0;
        bool rowDownFlag = false;
        
        for (char c : s) {
            result[curRow] += c;
            if (curRow % (numRows-1) == 0)
                rowDownFlag = ! rowDownFlag;
            
            // next row index
            curRow += rowDownFlag ? 1 : -1;
        }
        
        string res;
        for (int i = 0; i < numRows; i++)
            res += result[i];
        
        return res;
    }
};
