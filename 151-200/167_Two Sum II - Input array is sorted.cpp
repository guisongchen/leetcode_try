/*

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

*/



// keypoints:
// fix one, binary search another one


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // use binary search
        
        for (int i = 0, n = numbers.size(); i < n; i++) {
            int cur = target - numbers[i];
            
            // search idx from i+1 to avoid reuse elements
            int left = i+1;
            int right = n; // use [left, right) form
            while (left < right) {
                int mid = left + (right-left)/2;
                
                if (numbers[mid] == cur) {
                    return vector<int>{i+1, mid+1}; // idx start at 1. idx ascending order
                } else if (numbers[mid] < cur) { // go right
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        
        return vector<int>{};
    }
};
