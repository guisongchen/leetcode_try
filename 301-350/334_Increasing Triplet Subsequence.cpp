/*

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ¡Ü i < j < k ¡Ü n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false

*/


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // brute force and dynamic planning
        // use two index to solve in O(n)
        if (nums.empty())
            return false;
        
        
        int num1 = INT_MAX, num2 = INT_MAX;
        
        for (auto& it : nums) {
            
            if (it <= num1) // use "<=" to make sure "it != num1 != num2"
                num1 = it;
            else if (it <= num2) // use "else if" to make sure num1 < it < num2
                num2 = it;
            else
                return true; // now  num1 < num2 < it, so it must be ascending order
        }
        
        return false;
        
    }
};