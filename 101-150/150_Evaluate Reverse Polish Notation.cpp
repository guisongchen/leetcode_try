/*

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

*/



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // split tokens into two parts: digits and signs, use stack
        int sum = 0;
        stack<int> s;
        for (auto it : tokens) {
            if (!isSign(it)) { // digits
                s.push(digit(it));
            } else { // signs
                char& ch = it[0];
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                
                // notice the order of x anf y, should be (y operator x)
                if (ch == '+' || ch == '-') {
                    sum = ch == '+' ? y+x : y-x;
                } else { // '*' or '/'
                    sum = ch == '*' ? y*x : y/x;
                }
                
                s.push(sum);
            }
        }
        
        // sum must be the only element in the stack
        return s.top();
    }
    
    bool isSign(string& s) {
        if (s == "+" || s == "-" || s == "*" || s == "/")
            return true;
        return false;
    }
    
    int digit(string& s) {
        int ret = 0;
        int negBit = 0;
        // handle pos or neg
        if (s[0] == '-') {
            negBit = 1;
        }
        
        for (int i = 0 + negBit, n = s.size(); i < n; i++) {
            ret = 10*ret + s[i] - '0';
        }
        
        return negBit == 0 ? ret : -ret;
    }
};
