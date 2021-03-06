/*

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

*/


// keypoints:
// 1. rules by oberservation:
// 2. for odd: dp[i] = dp[i/2] + 1,  aka move 1 bit to *2, add 1 bit to make odd 
// 3. for even: dp[i] = dp[i/2]. aka only move 1 bit, not add

class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> dp(num+1, 0);
        
        for (int i = 1; i <= num; ++i) {
            if (i % 2)
                dp[i] = dp[i/2] + 1;
            else
                dp[i] = dp[i/2];
            
        }
        
        return dp;
        
    }
};


class Solution {
public:
    vector<int> countBits(int num) {
        // use build in function
        // not use build in function
        vector<int> ret(num+1, 0);
        
        for (int i = 1; i <= num; ++i) {
            ret[i] = ret[i&(i-1)] + 1;
        }
        
        return ret;
    }
};
