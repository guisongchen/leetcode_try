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

// solution 1
// 1. use dynamic planning(which needs given recursive fomular)
// 2. two sub-problem: find maxLen and startIdx
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

        for (int len = 2; len <= n; len++) { // aim to find maxLen
            for (int startIdx = 0; startIdx <= n-len; startIdx++) { // aim to find Best startIdx 
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

// solution 2: use manacher's algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        // use manacher's algorithm
        
        // step 1: padding to unite even and odd case
        string t = "$#";
        for (int i = 0, n = s.size(); i < n; ++i) {
            t += s[i];
            t + = "#";
        }
        
        // step 2: init parameters
        vector<int> p(t.size(), 0);  // palindrome length of string t

        // we use center of prev longestPalindrome to compute center of current longestPalindrome
        // which give us recursive formula
        int prevCtr = 0, prevR = 0;
        
        // init return value: maxCtr and maxR
        int maxCtr = 0, maxR = 0;
        
        // compute p[i] recursively, since we add "$" at first, means p[0] = 0
        // we start form i = 1
        for (int i = 1, n = t.size(); i < n; ++i) {
            
            // do recuesive
            
            //       j      mirror        prevCtr   prevR       i
            //       |         |            |          |        |
            // -----xxxxx-------------------x----------------xxxxxxx--------------
            if (prevR <= i) 
                p[i] = 1;
            
            // mirror of prevR   j             prevCtr     i               prevR
            // |                 |             |           |                |
            // ---------------xxxxxxx----------x--------xxxxxxx--------------
            // 
            
            else {
                if (prevR >= i + p[i])
            }
            
            
            
        }
    }
};
