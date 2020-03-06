/*

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16 
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4 
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0 
Explanation: No such pair of words.

*/

// keypoints:
// 1. find two string which not share common letters
// 2. find the maximum product
// solution 1: brutual force, dfs
// solution 2: hash table
// use int(32 bits) to represent occured characters in word(since only 26 characters in ASCII)
// if two words share no common character: int a & int b == 0


class Solution {
public:
    int maxProduct(vector<string>& words) {
        // keypoints:
        // 1. find two string which not share common letters
        // 2. find the maximum product
        if (words.empty())
            return 0;
        
        int ret = 0, n = words.size();
        
        // use bit operation to reduce compare cost
        // use 26 bits to map characters
        vector<int> mask;
        for (auto& word : words) {
            
            int num = 0;
            for (auto& ch : word) {
                num |= 1 << ch - 'a';
            }
            
            mask.push_back(num);
        }
        
        for (int i = 0; i < n; ++i) {
            
            string& cur = words[i];        
            for (int j = i+1; j < n; ++j) {
                 
                 if (!(mask[i] & mask[j])) { // no common character
                    ret = max(ret, static_cast<int>(cur.size() * words[j].size()));
                }
            }
        }
        
        return ret;
    }
};



class Solution {
public:
    int maxProduct(vector<string>& words) {
        // keypoints:
        // 1. find two string which not share common letters
        // 2. find the maximum product
        if (words.empty())
            return 0;
        
        sort(words.begin(), words.end(), 
             [] (string& a, string& b) { return a.size() > b.size(); } );
        
        int ret = 0, n = words.size();
        for (int i = 0; i < n; ++i) {
            string& cur = words[i];
            for (int j = i+1; j < n; ++j) {
                
                int cnt = static_cast<int>(cur.size() * words[j].size());
                
                if (cnt <= ret)
                    break;
                else if (checkWord(cur, words[j])) {
                    ret = cnt;
                }
            }
        }
        
        return ret;
    }
    
    // use bit operation to reduce compare cost
    bool checkWord(string& cur, string& next) {
        for (int i = 0, m = cur.size(); i < m; ++i) {
            char& temp = cur[i];
            for (int j = 0, n = next.size(); j < n; ++j) {
                if (temp == next[j])
                    return false;
            }
        }
        
        return true;
    }
};
