/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

// keypoints:
// 1. use dfs to find all matched pairs
// 2. parentheses must all start from '('
// 3. number of '(' must equal to number of ')' n (a.k.a left = right)
// 4. when use left?   left < n
// 5. when use right?  right < left

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // define return value
        vector<string> ret;
        // null case
        if (n < 1)
            return ret;
        
        // string s = {"("}; 
        // int left = 1, right = 0;
        // it must be '(', left = 1
        dfs(ret, n, "(", 1, 0);
        return ret;
    }
    
private:
    // NOT use reference to avoid backtrace
    void dfs(vector<string>& ret, const int& n, 
             string s, int left, int right) {
        if (left == n && right == n) {
            ret.push_back(s);
            return;
        }
        
        // if left < n, free to use left
        // since pass by value, avoid backtrace(s.pop_back(), left--)
        if (left < n) 
            dfs(ret, n, s+'(', left+1, right);
        
        // if right < left, free to use right
        if (right < left) 
            dfs(ret, n, s+')', left, right+1);
    }
    
};
