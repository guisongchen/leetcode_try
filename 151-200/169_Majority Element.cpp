/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        return nums[nums.size()/2];
    }
};



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt = 0;
        int candidate = 0;
        
        // useful when and ONLY when more than n/2 repeaters exist
        for (auto num : nums) {
            if (cnt == 0) { // prev candidate is weak, since exist num occur times equal to it(so cnt reduce to zero)
                candidate = num; // update candidate and cnt
                ++cnt;
            } else {
                // if duplicted, increase, if not, reduce
                // if cnt = 0, means two number now occur sanme times, no one will be over n/2
                candidate == num ? ++cnt : --cnt; 
            }
        }
        
        return candidate;
    }
};
