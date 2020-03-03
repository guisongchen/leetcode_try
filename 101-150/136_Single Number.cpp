/*

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // first idea is sort and double pointer
        // O(NlogN)
        
        // if O(N) and O(1), use bit operate: XOR
        
        int ret = 0; // must be 0 to keep nums[0]
        for (auto item : nums) {
            ret ^= item;
        }
        return ret;
    }
};
