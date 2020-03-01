/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/

// keypoints:
// 1. use longer length string store return reslut
// 2. padding shorter string at the beginning with zeros to keep two strings aligned
// 3. take care about carry, especially for i = 0 case

class Solution {
public:
    string addBinary(string a, string b) {
        // use the long string as return
        string longStr(b);
        string shortStr(a);
        if (a.size() > b.size()) {
            longStr = a;
            shortStr = b;
        }
        
        // padding for them both have same length
        shortStr.insert(0, longStr.size()-shortStr.size(), '0');
        
        for (int i = longStr.size()-1; i >= 0; i--) {
            longStr[i] = longStr[i] + shortStr[i] - '0';
            
            // "111" "111"
            if (i > 0 && longStr[i] >= '2') {
                longStr[i] -= 2;
                longStr[i-1] += 1;
            }
        }
        
        if (longStr[0] >= '2') {
            longStr[0] -= 2;
            longStr.insert(0, 1, '1');
        }
        
        return longStr;
    }
};
