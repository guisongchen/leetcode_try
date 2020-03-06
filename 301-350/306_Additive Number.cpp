/*

Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

 

Example 1:

Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199. 
             1 + 99 = 100, 99 + 100 = 199
 

Constraints:

num consists only of digits '0'-'9'.
1 <= num.length <= 35
Follow up:
How would you handle overflow for very large input integers?

*/


class Solution {
public:
    bool isAdditiveNumber(string num) {
        // select first two substring, consider remain part as the sum of first two
        if (num.size() < 3)
            return false;
        
        for (int i = 1, n = num.size(); i < n+1; ++i) {
            string sub1 = num.substr(0, i);
            if (i > 1 && sub1[0] == '0') // if i == 1, means '0', acceptable
                break; // number with leading 0
            
            for (int j = i+1; j < n+1; ++j) {
                string sub2 = num.substr(i, j-i);
                if (j-i > 1 && sub2[0] == '0')
                    break;
                if (checkSum(sub1, sub2, num.substr(j, n-j)))
                    return true;
            }
        }
        
        return false;
    }
    
    bool checkSum(string sub1, string sub2, string rem) {
        
        int r = rem.size();
        if (r == 0 || r > 1 && rem[0] == '0')
            return false;
        string temp = to_string(stol(sub1)+stol(sub2));
        
        if (temp.size() > rem.size())
            return false;
        else if (temp.size() == rem.size()) // sub1, sub2, rem is ok
            return temp == rem;
        else if (temp != rem.substr(0, temp.size())) // check: sub1+sub2 == rem(0, temp.size())
            return false;
        
        // check: sub1, sub2, temp, rem-temp
        return checkSum(sub2, temp, rem.substr(temp.size(), r-temp.size()));
    }
};
