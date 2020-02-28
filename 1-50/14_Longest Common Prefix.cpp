/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

// keypoints:
// 1. corner cases

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int lastCnt = 0;
        const int n = strs.size();
        if (n == 0)
            return "";
        else if (n == 1)
            return strs[0];
        else
            lastCnt = strs[0].size(); // prefix equal to full size for 1st str 
        
        // use idx NOT string to save space
        // string& st = strs[0];
        for (int i = 1; i < n; i++) {
            //string& s = strs[i];
            int curCnt = 0;
            
            for (int j = 0; j < lastCnt; j++) { // use lastCnt as threshold
                if (strs[0][j] == strs[i][j])
                    curCnt++;
                else
                    break;
            }
            
            if (curCnt == 0 || i == n - 1)
                return strs[0].substr(0, curCnt);        
            lastCnt = curCnt;
        }
        
        return "";
    }
};
