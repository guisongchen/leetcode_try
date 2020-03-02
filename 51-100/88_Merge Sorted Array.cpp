/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

// kepoints:
// 1. since array space(use nums1) and amount(m+n) are given, 
//    we just need to put correct elements into given index
// 2. we do it from end to begin, because end is free but head has valid numbers
//    id start from head, we have to move elements..
// 3. of course, we can use insert sort algorithm

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // corner case
        if (n < 1)
            return;
        
        // basic idea: since we get space at nums1
        // and we should start form end, not beginning
        // if we start from begnning, we need to decide how to move
        // and also move num frequently, it's not good
        
        int i = m-1, j = n-1, idx = m+n-1;
        while (i >= 0 && j >= 0 && idx >= 0) {
            if (nums1[i] < nums2[j]) {
                nums1[idx] = nums2[j];
                j--;
            } else {
                nums1[idx] = nums1[i];
                i--;
            }
            
            idx--;
        }
        
        // if i > 0, since we use nums1 as return, no need to do anything
        // if j > 0, move remain num to nums1
        
        while (j >= 0 && idx >= 0) {
            nums1[idx] = nums2[j];
            j--;
            idx--;
        }
    }
};
