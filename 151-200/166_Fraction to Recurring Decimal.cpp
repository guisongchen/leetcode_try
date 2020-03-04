/*

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"

*/

// keypoints:
// 1. use ^ to check sign is the same or not
// 2. remind*10 / divisor to get next decimal


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        
        string ret;
        // negative case
        if (numerator>0 ^ denominator>0)
            ret += "-";
        
        long n = labs(numerator);
        long d = labs(denominator);
        long r = n % d;
        
        ret += to_string(n / d);
        if (r == 0)
            return ret;
        ret += ".";
        
        unordered_map<long, int> rs;
        while (r) {
            
            // if remainer repeat, which means cycle begin
            // insert "(" at the first appear position
            if (rs.find(r) != rs.end()) {
                ret.insert(rs[r], "(");
                ret += ")";
                break;
            }
            
            // postion in ret
            rs[r] = ret.size();
            
            // get next digit of decimal(by multiply 10)
            r *= 10;
            ret += to_string(r/d);
            
            // get remainer
            r %= d;
        }
        
        return ret;
    }
};
