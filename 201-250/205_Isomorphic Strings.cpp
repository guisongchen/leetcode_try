/*

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.

*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // use array as hash table
        // since character ASCI only have 256 elements, we will use it
        // idx is ASCI of character, value is last occur idx
        int hash1[256] = {0}; // all init as 0
        int hash2[256] = {0};
        
        for (int i = 0, n = s.size(); i < n; ++i) {
            if (hash1[s[i]] != hash2[t[i]]) // pattern not match
                return false;
            
            // init default value is 0, if i = 0,  hash2[t[i]] = i = 0
            // we don't know update or not
            // so update key value by cur i + 1(or 2,3...)
            hash2[t[i]] = i+1;       
            hash1[s[i]] = i+1;  
        }
        
        return true;
    }
};
