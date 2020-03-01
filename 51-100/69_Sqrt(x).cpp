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
*/

// keypoints: use Newton method
// x^2 - n = 0, solve x;
// init x0, get tagent line though x0, intersect  x-axis at point x1
// x1 act same as x0, get x2....xn
// when stop ? xj - xi <= 1e-6
// f(x) = x^2 - n = 0  --> f'(x) = 2*x
// tagent line:   f(xj) = f(xi) + f'(xi)(xj-xi)
// intersect at x-axis:  f(xi) + f'(xi)(xj-xi) = 0
// -> xj = -f(xi)/f'(xi) + xi,   since f'(xi) = 2xi
// -> xj = xi - f(xi)/2xi = xi - (xi^2 - n)/2xi = xi/2 + n/2xi = (xi + n/xi) / 2
// use double type here


class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        
        double prev = 0.0, cur = 1.0;
        
        while (abs(prev-cur) > 1e-6) {
            prev = cur;
            cur = (cur + x/cur) / 2;
        }
        
        return int(cur);
    }
};

// keypoints:
// 1. this range should between [1, x/2 + 1]
// 2. use binary search to find answer
// 3. looking for right boundary
// 4. caution about overflow
//    -->  mid = left + (right-left)/2
//    -->  mid*mid == x ---> mid = x /mid
             
class Solution {
public:
    int mySqrt(int x) {
        // corner case
        if (x < 2)
            return x;
        
        // notice the fact: since x > 1, sqrt_x must lies on the range of [1, x]
        // use binary search
        
        // NOTE: since x > 2, we have sqrt(x) < x
        int left = 1, right = x/2+1;
        while (left < right) {
            
            // NOTE: NOT use (left+right) / 2, if left=right=INT_MAX, overflow!!
            int mid = left + (right-left) / 2;
            
            // NOTE: NOT use mid*mid = x, if mid=INT_MAX, overflow!!
            if (mid == x/mid) {
                left = mid + 1;
            } else {
                if (mid > x/mid) {
                    right = mid;
                }  else {
                    left = mid + 1;
                }
            }
        }
        
        // since we truncated sqrt, return left-1
        return left-1;
    }
};
