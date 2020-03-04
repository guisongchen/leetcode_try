/*

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"

*/



// keypoints:
// 1. in range [1, 26], Z stands for 26
// 2. in range [27,infinite], A stands for 26
// 3. reverse to get final result


class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while (n) {
            // when "0~26", Z stands for "26"
            if (n % 26 == 0) {
                ret += 'Z';
                n = n/26 - 1;
            } else { // when need carry, "A" stands for "26"
                ret += 'A' + n % 26 - 1;
                n = n/26;
            }
        }
        
        for (int i = 0, j = ret.size()-1; i < j; ++i, --j) {
            swap(ret[i], ret[j]);
        }
        
        return ret;
    }
};
