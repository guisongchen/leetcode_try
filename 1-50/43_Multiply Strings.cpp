/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

// keypoints:
// following rule should be observed:
// 1. (n1*n2).size <= n1.size+n2.size
// 2. i-th 0f num1 * j-th of num2, result stay at i+j and i+j+1 of final multiply result
// 3. add all data at each position together, we get final result
// 4. careful about leading zero 

class Solution {
public:
    string multiply(string num1, string num2) {
        // most important thing: (n1*n2).size = n1.size+n2.size OR n1.size+n2.size-1
        string ret(num1.size()+num2.size(), '0');
        
        // from right to left
        for (int i = num1.size()-1; i >= 0; i--) {
            for (int j = num2.size()-1; j >=0; j--) {
                
                // curr_comb + other_comb(which result lay on this position)
                // i+j+1 is position idx, there are many multiply combination lies on this pos
                int data = (num1[i]-'0') * (num2[j]-'0') + (ret[i+j+1]-'0');
                
                // current pos: i+j+1
                ret[i+j+1] = data % 10 + '0';
                
                // next pos need add carry, since we init ret with '0'
                // won't need add '0' here
                ret[i+j] += data / 10;
            }
        }
        
        if (ret[0] == '0') {
            if (ret[1] == '0') {
                return "0";
            } else {
                return ret.substr(1);
            }
        } else {
            return ret;
        }
    }
};
