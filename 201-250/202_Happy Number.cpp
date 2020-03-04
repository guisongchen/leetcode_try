/*

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

// keypoints:
// 1. tricky part is how to deicide return false?  if sum == 1, return true, but when return false?
// --> sum of square if not equal to 1, must equal to some occoured number
// 2. use hashSet to query sum exist or not(set also makes sure no duplicates exist)


class Solution {
public:
    bool isHappy(int n) {
        // use set to keep square result
        // 1. if square result = 1; true
        // 2. if square result occured twice, false
        unordered_set<int> hash;
        int sum = 0;
        while (n != 1) {
            sum = 0;
            while (n) {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            
            if (sum == 1) {
                return true;
            } else if (hash.count(sum)) {
                return false;
            }
            
            hash.insert(sum);
            n = sum;
        }
        
        return true;
    }
};
