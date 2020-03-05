/*

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

*/

// keypoints:
// 1. use insert sort algorithm
// 2. do duplicate check while sorting array


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // use travial sort method
        
        for (int i = 1, n = nums.size(); i < n; ++i) {
            int temp = nums[i];
            int j = i;
            while(j > 0 && nums[j-1] > temp) {
                nums[j] = nums[j-1];
                --j;
            }
            
            if (j > 0 && nums[j-1] == temp)
                return true;
            
            nums[j] = temp;
        }
        
        return false;
    }
};
