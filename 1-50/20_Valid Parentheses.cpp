/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

// keypoints:
// 1. use stack to verify string
// 2. use hash to map left and right parentheses

class Solution {
public:
    bool isValid(string s) {     
        stack<char> st;
        unordered_map<char, char> mp{{'(', ')'},
                                     {'{', '}'},
                                     {'[', ']'}};
        
        for (char cur : s) {
            if (cur == '(' || cur == '{' || cur == '[') {
                st.push(cur);
            } else {
                // corner case: }(){
                if (st.empty())
                    return false;
                
                char& last = st.top();
                if (cur == mp[last]) {
                    st.pop(); // check un-empty, safe
                } else {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};
