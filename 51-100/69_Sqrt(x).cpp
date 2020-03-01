/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
             
class Solution {
public:
    int mySqrt(int x) {
        // corner case
        if (x < 2)
            return x;
        
        // notice the fact: since x > 1, sqrt_x must lies on the range of [1, n]
        // use binary search
        
        // NOTE: since x > 2, we have sqrt(x) < x/2
        int left = 1, right = x/2;
        while (left <= right) {
            
            // NOTE: NOT use (left+right) / 2, if left=right=INT_MAX, overflow!!
            int mid = left + (right-left) / 2;
            
            // NOTE: NOT use mid*mid = x, if mid=INT_MAX, overflow!!
            if (mid == x/mid) {
                return mid;
            } else {
                if (mid > x/mid) {
                    right = mid - 1;
                }  else {
                    left = mid + 1;
                }
            }
        }
        
        // if not return before, answer must lies on left or right, since we truncated sqrt
        // choose the minmum
        return min(left, right);
    }
};
