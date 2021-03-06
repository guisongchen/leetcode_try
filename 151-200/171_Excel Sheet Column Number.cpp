/*

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701

*/


// keypoints:
// 1. careful about the iteration expression
// 2. need to add last bit value to current value, move forward one bit, multiply 26

class Solution {
public:
    int titleToNumber(string s) {
        
        int ret = 0; 
        for (int i = 0, n = s.size(); i < n; ++i) {
            ret *= 26;
            ret += s[i] - 'A' + 1;
        }

        return ret;
    }
};
