/*

Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false

*/


class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        // only one '1' in all bit. others bits must be '0'
        // last bit must be zero except 1
        int cnt = 0;
        while (n > 0) {
            cnt += n & 1;
            n >>= 1;
        }
        
        return cnt == 1;
    }
};
