/*

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

*/

// keypoints:
// 1. use double pointers to valid palindrome, head and tail pointers
// 2. ignore invalid characters. careful about capital and lower cases(ASCII gap is 32)
// 3. corener case: single character or nullptr

class Solution {
public:
    bool isPalindrome(string s) {
        // keypoint: consider one character as true
        if (s.size() <= 1)
            return true;
        
        // two pointer, head and tail
        int left = 0;
        int right = s.size();
        
        while (left < right) {
            
            // caution about idx overflow
            while (left < right && !isValid(s, left)) {
                left++;
            }
            
            while (left < right && !isValid(s, right)) {
                right--;
            }
            
            // trick: low and caps cases transform
            if ((s[left]+32-'a')%32 != (s[right]+32-'a')%32) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        
        return true;
        
    }

    bool isValid(string& s, int i) {
        return (s[i] >= '0' && s[i] <= '9') ||
               (s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= 'A' && s[i] <= 'Z');
    }
    
    
};
