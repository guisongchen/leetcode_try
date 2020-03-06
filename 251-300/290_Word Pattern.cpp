/*

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.

*/

// keypoints: use hash table
// 1. hash is one to one map
// 2. same character in pattern must map to the same string
// 3. same string msut map to the same character in pattern
// 


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // corner case
        if (pattern.size() == 0)
            return false;
   
        int start = 0;     
        int n = str.size();
        unordered_map<string, char> hash;
        string cur; // memory prev character in pattern array
        
        int idx = 0; // idx of pattern
        for (int i = start; i < n; ++i) {
            if (str[i] == ' ' || i == n-1) { // notice last string has no " " behind
                string temp = i == n-1 ? str.substr(start, n-start) : 
                                         str.substr(start, i-start);    
                start = i+1;
                char& ch = pattern[idx++];
                
                if (!hash.count(temp)) {
                    if (cur.find(ch) == string::npos) {
                        hash[temp] = ch;
                        cur += ch;
                    }
                    else // ch exist in cur, means two patter ch map to the same string
                        return false;
                } else if (hash[temp] != ch){  // same string map to diefferent pattern characher !!
                    return false;
                }
            }
        }
        
        return idx == pattern.size();
    }
};
