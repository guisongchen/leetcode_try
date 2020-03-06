/*

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

*/


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        // divide and conque
        // consider () may be added at both side of each sign
        if (input.size() == 0)
            return vector<int>{};
        
        vector<int> ret;
        for (int i = 0, n = input.size(); i < n; ++i) {
            char& ch = input[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1, n-i-1));
                
                for (auto n1 : left) {
                    for (auto n2 : right) {
                        if (ch == '+')
                            ret.push_back(n1 + n2);
                        else if (ch == '-')
                            ret.push_back(n1 - n2);
                        else
                            ret.push_back(n1 * n2);
                    }
                }
            }
        }
        
        // only digits, no sign
        if (ret.empty()) {
            int sum = 0;
            for (auto ch : input) {
                sum = 10*sum + ch - '0';
            }
            ret.push_back(sum);
        }
        
        return ret;
    }
};
