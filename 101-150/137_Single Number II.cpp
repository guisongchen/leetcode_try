/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // basically bit operator is only choise
        // for even times duplicated, use XOR will be good
        // for odd times, there may be trouble
        
        // keypoints: 
        // 1. remember duplicated times by XOR
        // 2. basic info about group operators:
        //    a\b  -> a & (~b)
        //    (a\b) union (b\a) -> a^b
        // 3. surpose a and b is bits num of '1', init a = 0, b = 0
        
        int a = 0, b = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            // use ^ to get duplicated info
            // if only use one num, update would be: 0-1-0, can't seperate 3rd duplicated
            // use a,b to update in path ab: 00-01-10 
            // get nums[i] '1' info and cut a info
            b = (b ^ nums[i]) & ~a;
            // get nums[i] '1' info and cut b info
            a = (a ^ nums[i]) & ~b;
        }
        
        return b;
    }
};
