/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

class Solution {
public:
    double myPow(double x, int n) {

        double ret = 1.0;
        
        // NOTE: can't simple use n = -n
        // it will be danger if n = INT_MIN
        if (n == INT_MIN) {
                n++; // -2^31 --> -2^31 + 1, safe !!
                ret *= 1.0/x;
            }
        
        if (n < 0) {
            x = 1.0/x;
            n = -n; // safe now
        }
        
        while (n) {
            if (n & 1) {
                ret *= x;
            }
            x *= x;
            
            // must make sure n > 0
            n >>= 1;
        }

        return ret;
    }
};
