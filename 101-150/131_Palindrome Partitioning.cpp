/*

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]

*/

// solution 1:
// 1. divide and conque, use dfs
// 2. start from idx 0, divide into s[0] and s[1~end]
// 3. check palindrome of those two, then divide s[1~end]

// solution 2
// 1. same idea with solution 1, but we use dynamic planning to check palindrome or not 


class Solution {
public:
    vector<vector<string>> partition(string s) {
        // do it recursively
        // 1. start from idx 0, divide into s[0] and s[1~end]
        // 2. check palindrome of those two, then divide s[1~end]
        
        vector<vector<string>> ret;
        vector<string> cur;
        partition(s, ret, cur);
        return ret;
    }
    
    void partition(string s, vector<vector<string>>& ret,
                   vector<string>& cur) {
        
        if (s.size() == 0) {
            ret.push_back(cur);
            return;
        }
        
        for (int i = 0, n = s.size(); i < n; i++) {
            string temp = s.substr(0, i+1);
            if (checkPalindrome(temp)) {
                cur.push_back(temp);
                partition(s.substr(i+1, n-i), ret, cur);
                cur.pop_back();
            }
        }
    }
    
    bool checkPalindrome(string& s) {
        if (s.size() < 2)
            return true;
        
        int left = 0;
        int right = s.size()-1;    
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        
        return true;
    }
};



class Solution {
public:
    vector<vector<string>> partition(string s) {
        // do it recursively
        // 1. start from idx 0, divide into s[0] and s[1~end]
        // 2. check palindrome of those two, then divide s[1~end]
        
        // to improve compute efficiency, we compute palindrome range first
        // this will use dynamic planning
        vector<vector<string>> ret;
        vector<string> cur;
        
        // compute palindrome range
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int end = 0; end < n; end++) {
            for (int start = 0; start <= end; start++) {
                // single character is palindrome, end == start, like 'a'
                if (start == end)
                    dp[start][end] = true;
                // end - start = 1, like 'aa', which dp[start+1][end-1] not exist
                // end - start = 2, like 'aba', which dp[start+1][end-1] is single char
                else if (s[start] == s[end] && (end-start == 1 || dp[start+1][end-1]))
                    dp[start][end] = true;
            }
        }
        
        partition(s, ret, dp, cur, 0);
        return ret;
    }
    
    void partition(string& s, vector<vector<string>>& ret,
                   vector<vector<bool>>& dp, vector<string>& cur, int start) {
        
        if (start == s.size()) {
            ret.push_back(cur);
            return;
        }
        
        for (int i = start, n = s.size(); i < n; i++) {
            if (dp[start][i]) {
                cur.push_back(s.substr(start, i-start+1));
                partition(s, ret, dp, cur, i+1);
                cur.pop_back();
            }
        }
    }
};
