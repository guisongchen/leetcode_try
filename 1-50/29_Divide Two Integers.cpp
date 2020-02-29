/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

// keypoints:
// 1. transform divident and devisor into positive number, then handle singal at return time
// 2. use taylor expension to do divide (32bit int) 
//    from 31 to 0 (32 bit)
//      dividend -= divisor << (31-i)
//      result += 1 << (31-i)
// 3. handle overflow(INT_MAX, INT_MIN), which INT_MIN = -2^31, INT_MAX = 2^31-1

class Solution {
public:
    int divide(int dividend, int divisor) {
        // taylor expension
        // a = y/x
        // y = x*1 + x*2^1 + ... + x*2^n = x + x<<1 + ... + x<<n)
        // a = 2^0 + 2^1 + ... + 2^n
        
        // corner case
        if (divisor == 0) // this won't happen
            return INT_MAX;
        
        if (dividend == 0)
            return 0;
        
        int ret = 0;
        
        // trick: use ^ to juadge same sign or not
        bool sameFlag = (dividend > 0) ^ (divisor < 0);
        
        // handle overflow corner case
        // -divident > INT_MAX <-- overflow
        // -2147483648 / -1 = 2147483647
        if (dividend == INT_MIN) { 
            if (divisor == INT_MIN) { // which means divisor = INT_MIN
                return 1;
            } else if (divisor == -1){
                return INT_MAX;
            } else if (divisor == 1){
                return INT_MIN;
            } else if (divisor == 2 || divisor == -2){
                return dividend>>1;
            } else {
                dividend = INT_MAX;
            }
        }
        
        if (divisor == INT_MIN) { 
            return 0;
        }
            
        // convert to positive num
        if (dividend < 0)
            dividend = -dividend;
        if (divisor < 0)
            divisor = -divisor;
        
        for (int i = 0; i < 32; i++) { 
            // trick: divisor << (31-i) very easy to overflow
            // dividend >> (31-i) is much safer
            if (dividend >> (31-i) >= divisor) {
                dividend -= divisor << (31-i);
                ret += 1 << (31-i);
            }
        }
        
        return sameFlag ?  ret : -ret;
    }
};
