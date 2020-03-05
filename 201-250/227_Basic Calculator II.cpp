/*

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.

*/


// keypoints:
// 1. calulate result in one pass
// 2. consider sign '+' and '-' as positive and negative
// 3. careful about / and *
// 4. use ASCII value to seperate nums and signs
//    order in ASCII: space, bracket, sign, digits, lower character, capitial
// 5. corner case: when i == n-1, we need to push the last num into stack!!
// 6. use long type in case overflow

class Solution {
public:
    int calculate(string s) {
        if (s.size() == 0)
            return 0;
        
        // init digit and prevSign
        long num = 0;
        char prev = '+';
        stack<long> st;
        
        for (int i = 0, n = s.size(); i < n; ++i) {
            
            char &cur = s[i];
            
            if (cur >= '0' && cur <= '9') {
                num = num*10 + cur - '0';
            } 
            
            if ((cur < '0' &&  cur != ' ') || i == n-1) { // reach end also need to push num
                
                if (prev == '+') {
                    st.push(num);
                } else if (prev == '-') {
                    st.push(-num);
                } else if (prev == '*' || prev == '/') {
                    long temp = st.top();
                    st.pop();
                    
                    temp = prev == '*' ? temp*num : temp/num;
                    st.push(temp);
                }
                
                prev = cur;
                num = 0;   
            }
        }
        
        long sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        
        return sum;
        
    }
};
