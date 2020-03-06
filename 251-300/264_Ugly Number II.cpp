/*

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.

*/


// keypoints:
// first ugly number is 1
// each num *2, *3, *5 is still ugly number
// if do multiply for each num, duplicate may exist, two ways to handle:
// 1. use three pointer i2,i3,i5 to identify next num which should be *2 or *3 or *5
//    i2, i3, i5 may be the same, but after multiply *2,*3,*5, will be different
// 2. new number is minmum of (i2*2, i3*3, i5*5)


class Solution {
public:
    int nthUglyNumber(int n) {
        // keypoints:
        // first ugly number is 1
        // each num *2, *3, *5 is still ugly number
        // if do multiply for each num, duplicate may exist, two ways to handle:
        // 1. use three pointer i2,i3,i5 to identify next num which should be *2 or *3 or *5
        //    i2, i3, i5 may be the same, but after multiply *2,*3,*5, will be different
        // 2. new number is minmum of (i2*2, i3*3, i5*5)
        
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> nums({1});
        
        while (nums.size() < n) {
            int cur = min(min(nums[i2]*2, nums[i3]*3), nums[i5]*5);
            nums.push_back(cur);
            
            if (cur == nums[i2]*2)
                ++i2; // move to next idx which should *2
            if (cur == nums[i3]*3)
                ++i3;
            if (cur == nums[i5]*5)
                ++i5;
        }
        
        return nums.back();
    }
};
