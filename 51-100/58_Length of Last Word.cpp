/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.size();
        
        // corner case: "a   " "aa  "
        // use cnt also as validFlag, if cnt > 0, start count
        int cnt = 0;
        for (int i = n-1; i >=0; i--) {
            if (!cnt) {
                if (s[i] != ' ') {
                    cnt++;
                }
            } else {
                if (s[i] == ' ')
                    break;
                cnt++;
            }
        }
        
        return cnt;
    }
};
