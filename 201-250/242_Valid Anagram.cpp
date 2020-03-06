/*

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/

// keypoints:
// 1. hash table is a nature choise
// 2. if only contains lowercase alphabets, we use int[26] as hash table
// 3. contain unicode characters --> int [256]



class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        unordered_map<char, int> hash;
        int cnt = 0;
        while (cnt < 26) {
            hash['a'+cnt] = 0;
            ++cnt;
        }
        
        for (int i = 0, n = s.size(); i < n; ++i) {
            ++hash[s[i]];
            --hash[t[i]];
        }
        
        for (auto it : hash) {
            if (it.second)
                return false;
        }
        
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        int hash[26] = {0};
        
        for (int i = 0, n = s.size(); i < n; ++i) {
            ++hash[s[i]-'a'];
            --hash[t[i]-'a'];
        }
        
        for (auto it : hash) {
            if (it)
                return false;
        }
        
        return true;
    }
};
