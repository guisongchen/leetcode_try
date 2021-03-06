/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

// keypoints:
// 1. array is sorted, and twice repeated is allowed
//   -> we only need to compare nums[i] and nums[i-2] !!


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // corner case
        if (nums.size() < 3)
            return nums.size();
        
        // think about when we need to move array and count
        // it only happens when nums[i] != nums[i-2]
        // why ? the array is sorted!!
        
        // big trick: compare current idx with "sorted" idx
        int cnt = 2;
        for (int i = 2, n = nums.size(); i < n; i++) {
            // basically we use i to split nums into two parts
            // left part is sorted, right part is original
            // and the value is update till cnt
            
            // so if num[i] is duplicated, skip. if not, update
            if (nums[i] != nums[cnt-2]) {
                
                // cnt <= i
                // if cur = i, of course ok, if duplicated exist: cnt < i
                // we only change element (nums[cnt]) before current idx i, safe!!
                nums[cnt] = nums[i];
                // first update value, then add count
                cnt++;
            }
        }
        
        return cnt;
    }
};
