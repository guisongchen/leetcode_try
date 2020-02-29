/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

// keypoints:
// 1. how to identify anagrams? -->  sort!
// 2. how to group?  -->  HashMap!
// little trick about hashmap: key-> sorted string, key value-> index in result vector(start from 0)
// -- anagram has same sorted string
// -- if hash[string] not exist, create a new empty vector<string> for result,
// -- if hash[string] exist, push_back into result[result.size()]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // use bit operater is not reasonable
        // "ab" "aab" are different
        // but bit |= each_of_"ab" and bit |= each_of_"aab" are the same
        
        // null case
        if (strs.size() < 2)
            return vector<vector<string>> {strs};
        
        // define return
        vector<vector<string>> ret;
        // use second "int" to trace ret size 
        // each key_string has a unique int(since int change with ret size)
        unordered_map<string, int> hashStr;
        
        for (int i = 0, n= strs.size(); i < n; i++) {
            
            string s = strs[i];
            sort(s.begin(), s.end());
            
            // if not exist, need to add one null space for ret
            // e.g. first string with int = 0, which also the first index of ret
            if (!hashStr.count(s)) {
                // bond key string to ret size
                hashStr[s] = ret.size();
                
                // create new space
                ret.push_back({});
            }
            
            // now ret[hashStr[s]] should exist OR have been created before
            ret[hashStr[s]].push_back(strs[i]);
        }
        
        return ret;
        
    }
};
