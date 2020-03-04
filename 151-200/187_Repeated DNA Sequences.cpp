/*

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]

*/


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // keypoint: use bit operation
        // storage 9 characters(27 bit), check 10-th character(3 bits sliding window)
        if (s.size() < 10)
            return vector<string>{};
        
        vector<string> ret;
        int mask = 0x7ffffff, cur = 0;
        unordered_map<int, int> hash;
        
        // get the first 9 characters
        for (int i = 0; i < 9; ++i) {
            // s[i] & 7 : get last 3 bits
            // becasue: ACGT last 3 bits are different
            // cur << 3 : left shift 3 bits, kind of like sliding window with size 3
            cur = (cur << 3) | (s[i] & 7);
        } 
        
        // start counting from the 10th
        for (int i = 9, n = s.size(); i < n; ++i) {
            // mask is to get last 9 characters
            cur = ((cur & mask) << 3) | (s[i] & 7);
            if (hash.count(cur)) {
                if (hash[cur] == 1) { // occur and occur once
                    ret.push_back(s.substr(i-9, 10));
                }
                ++hash[cur]; // to avoid push duplicated into ret
            } else {
                hash[cur] = 1;
            }
        }
        
        return ret;  
    }
};
