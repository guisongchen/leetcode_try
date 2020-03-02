/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/


// keypoints:
// 1. since only three colors, we can use double pointers to handle it
//    current index is i
// 2. red(0) move to head, blue(2) move to end, skip white(1)
// 3. notice: swap(nums[i--], nums[blue--]);
//    swaped num may be zero, so need to check it again, use --i to keep index unchanged
// 4. notice: i <= blue, after blue is sorted 2, so it must stop here
//    can't be red < blue or i < n, those will redraw what we did
//    once i > blue, it will swap all 2 to 1 !!


class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int red = 0, blue = nums.size() - 1;
        
        
        //    notice: i <= blue, after blue is sorted 2, so it must stop here
        //    can't be red < blue or i < n, those will redraw what we did
        //    once i > blue, it will swap all 2 to 1 !!
        
        for (int i = 0; i <= blue; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[red++]);
            } else if (nums[i] == 2) {
                //    notice: swap(nums[i--], nums[blue--]);
                //    swaped num may be zero, so need to check it again
                //    use --i to keep index unchanged
                swap(nums[i--], nums[blue--]);
            }
        }
        
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // insert sort
        for (int i = 1, n = nums.size(); i < n; i++) {
            int temp = nums[i];
            // compare to prevs
            int j = 0;
            for (j = i; j > 0; j--) {
                // if prev is big than nums[i], move to right
                if (nums[j-1] > temp) {
                    nums[j] = nums[j-1];
                } else {
                    break; // find the place for temp, temp > nums[j-1], should stay at j
                }
            }
            nums[j] = temp;
        }
    }
};
