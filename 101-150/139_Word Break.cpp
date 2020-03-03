/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/


// solution 1:
// 1. brutal force, use dfs and memo array, memo[i] means substring i~n in wordlist
// 2. use hashSet to speed up search

// solution 2:
// 1. use dynamic planning
// 2. use hashSet to speed up search

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return check(s, wordSet, 0, memo);
    }
    bool check(string s, unordered_set<string>& wordSet, int start, vector<int>& memo) {
        if (start >= s.size()) return true;
        if (memo[start] != -1) return memo[start];
        for (int i = start + 1; i <= s.size(); ++i) {
            if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, memo)) {
                return memo[start] = 1;
            }
        }
        return memo[start] = 0;
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // one good idea may be arrange string in wordDict to match string s
        // use hash to support efficient query
        
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        
        // means [0,i) range is breakable, not including i
        // [0,0), [0,1), ..., [0,i), ..., [0,n-1)
        // notice i-th is ith-charater of s, start from 1
        vector<bool> dp(s.size()+1, false);
        dp[0] = true; // init to start loop
        
        // divide and consque
        // first: divide 
        // sub-problem: check each [0,i) is breakable or not, update dp[i]
        // when i = n is the result we want, [0,n) == [0,n-1]
        
        // second: consque
        // split 0~i into two parts: [0,j), [j,i)
        // update j range status according to [0,j) range status 
        
        // from 1 to n, update status form 0 to n-1
        for (int i = 1, n = dp.size(); i < n; i++) {
            
            // j must less than i, since we use prev info(j) update cur info(i)
            // the range is [j,i)
            for (int j = 0; j < i; j++) {
                
                // target: dp[i] -> [0,i)
                // part1: dp[j] -> [0,j)
                // part2: [j, i) -> substr(j, i-1-j+1)
                if (dp[j] && hash.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp.back();
    
    }
};
