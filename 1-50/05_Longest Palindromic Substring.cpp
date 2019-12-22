/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        
        const int n = s.size();
        
        // corner case: single character or empty
        if (n == 1 || n == 0)
            return s;
        
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        int bestStartIdx = 0;
        int maxLen = 1;
        
        // dp[i][j] means substring s[i] ... s[j] is a palindrome
        // forward formula:  i i+1 ......j-1 j
        // dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
        
        // base case
        for (int i = 0; i < n-1; i++) {
            dp[i][i] = true; // s[i] == s[i]
            dp[i][i+1] = (s[i] == s[i+1]); // corner case: aa bb
        }
        dp[n-1][n-1] = true;  

        for (int len = 2; len <= n; len++) { 
            for (int startIdx = 0; startIdx <= n-len; startIdx++) {
                int endIdx = startIdx+len-1;
                if (s[startIdx] == s[endIdx] &&
                    (endIdx == startIdx+1 || dp[startIdx+1][endIdx-1])) {
                    
                    dp[startIdx][endIdx] = true;
                    
                    if (len > maxLen) {
                        bestStartIdx = startIdx;
                        maxLen = len;
                    }
                }
            }
        }
        
        return s.substr(bestStartIdx, maxLen);
    }
};
