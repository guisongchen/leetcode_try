/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

class Solution {
public:
    int numDecodings(string s) {
        // corner case "010"
        if (s.empty() || s[0] == '0')
            return 0;
        
        vector<int> dp(s.size()+1, 0);
        
        // we have make sure s[0] != '0' before
        dp[0] = 1;
        
        // transform equation, we consider 3 elements as a tuple
        // dp[i-1] stands for '1' cases, dp[i-2] stands for '12' cases
        // dp[i] = dp[i-1] + dp[i-2]
        //
        // also we should notice dp pointer is 1 step ahead of string pointer
        // aka we stand out of the string(not at the end), and count
        
        for (int i = 1, n = dp.size(); i < n; i++) {
            if (s[i-1] == '0')
                dp[i] += 0;  // i-1_th is '0', no contribute to i
            else
                dp[i] += dp[i-1];
            
            if (i > 1 && s.substr(i-2,2) <= "26" && s.substr(i-2, 2) >= "10")
                dp[i] += dp[i-2];
            else
                dp[i] += 0; // "i-1, i-2" out range, no contribute to i
            
            // no way
            if (dp[i] == 0)
                break;
        }
        
        return dp.back();
    }
};
