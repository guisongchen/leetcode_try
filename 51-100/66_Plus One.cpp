/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

// keypoint:
// 1. corner case: 9, 99, 999,   heading and ending zeros

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // corner case 9, 99
        // NULL case
        if (digits.size() == 0)
            return digits;
        
        int n = digits.size();
        digits[n-1] += 1;
        for (int i = n-1; i >= 1; i--) {
            if (digits[i] == 10) {
                digits[i] = 0;
                digits[i-1] += 1;
            }
        }
        
        // 99
        if (digits[0] == 10) {
            digits[0] = 1;
            digits.push_back(0);
        }
        
        return digits;
    }
};
