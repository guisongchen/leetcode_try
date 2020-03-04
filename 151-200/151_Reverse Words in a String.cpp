/*

Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

*/

// keypoint: reverse entire string, then reverse single word!!
// 1. corner cases: leading space,  multi-space
// 2. between word and word should have space
// 3. update reversed string size and resize string length

class Solution {
public:
    string reverseWords(string s) {
        // keypoint: reverse entire string, then reverse single word!!
        
        // reverse entire string
        reverseHelper(s, 0, s.size()-1);
        
        // keypoints:
        // 1. use strIdx as the idx of return string
        // 2. skip all space, use charater as separate signal
        //    word between two space is naturely storage in string with correct idx
        // 3. after settle word in right place then do reverse
        int strIdx = 0; // idx of return string
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] != ' ') {
                if (strIdx != 0) // not at the begin of string
                    s[strIdx++] = ' ';
                
                int j = i;
                while (j < n && s[j] != ' ')
                    s[strIdx++] = s[j++];
                
                reverseHelper(s, strIdx-(j-i), strIdx-1);
                i = j;
            }
        }
        
        s.resize(strIdx);
        return s;
    }
    
    void reverseHelper(string& s, int left, int right) {

        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            ++left;
            --right;
        }
    }
};
