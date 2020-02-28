/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

// keypoints:
// 1. seperate every single digit from nums, and rebuild reverse number
// 2. corner case like: negative number, number ending with one or more zeros
// 3. when rebuild number, must careful about overflow, both negative and positive case
// 4. INT_MAX = 2^31-1, INT_MIN = -2^31, not simple flip signal

class Solution {
public:
    int reverse(int x) {
        
        int remain = 0;
        int res = 0;
        
        while (x) {
            remain = x % 10;
            x = x / 10;
            
            // check one step before final result in case overflow
            // corner case: 2147483647
            if (res > INT_MAX/10 || (res == INT_MAX/10 && remain > 7))
                return 0;
            // corner case: -2147483648
            if (res < INT_MIN/10 || (res == INT_MIN/10 && remain < -8))
                return 0;
            // set at last in case overflow
            res = res * 10 + remain;
        }

        return res;

    }
};
