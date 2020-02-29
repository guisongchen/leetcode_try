/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        // null case
        if (needle.size() == 0)
            return 0;
        
        int cnt = 0, idx = -1;
        int m = needle.size();
        
        // cut: haystack.sub(i).length >= needle.size()
        // if not, substr lenght will not equal to needle
        for (int i = 0, n = haystack.size()-m+1; i < n; i++) {
            if (haystack[i] != needle[0]) {
                continue;
            } else {
                cnt = 1;
                idx = i;
            }
            
            // the following m-1 character must all be the same
            for (int j = i+1; j < i+m; j++) {
                if (haystack[j] == needle[cnt]) {
                    cnt++;
                } else { break; }
            }
            if (cnt == m)
                return idx;
                
        }
        
        return -1;
    }
};
