/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

// keypoints:
// 1. seperate number into two part: left and right, compare left and reverse-right
//    even and odd amounts digits should treated differently
// 2. corner case: negative number, single number, number ends with zeros

class Solution {
public:
    bool isPalindrome(int x) {
        // corner case
        if (x >= 0 && x < 10)
            return true;
        
        // must handle x%10 == 0 here, or will be trouble later: reverse start with 0 
        if (x < 0 || x % 10 == 0)
            return false;
        
        int reverse = 0;
        
        // make sure only remained x > reverse -->continue
        // for odd  12321   remain: 12 < reverse: 123 stop, get midpoint
        // for even 1221    remain: 12 = reverse: 12  stop, get midpoint   
        while (x > reverse) {
            reverse= reverse * 10 + x % 10;
            x = x / 10;
        }
        
        // if digits number is even : reverse = remian; 
        // for odd cese: reverse/10 = remian, using /10 to clean mid-point, e.g.: 12121
        return x == reverse || x == reverse/10 ;
    }
};
