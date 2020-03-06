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


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // corner case
        if (pattern.size() == 0)
            return false;
   
        int start = 0;     
        int n = str.size();
        unordered_map<string, char> hash;
        string cur;
        
        int idx = 0; // idx of pattern
        for (int i = start; i < n; ++i) {
            if (str[i] == ' ' || i == n-1) {
                string temp = i == n-1 ? str.substr(start, n-start) : 
                                         str.substr(start, i-start);    
                start = i+1;
                char& ch = pattern[idx++];
                
                if (!hash.count(temp)) {
                    if (cur.find(ch) == string::npos) {
                        hash[temp] = ch;
                        cur += ch;
                    }
                    else
                        return false;
                } else if (hash[temp] != ch){
                    return false;
                }
            }
        }
        
        return idx == pattern.size();
    }
};
