/*

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]

*/


// keypoints:
// 1. only exist two candidates: n1 and n2
// 2. at most exist 2 appear more than 3/n, since 3*(3/n+1) > n

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ret;
        // two candidates: n1 and n2
        // at most exist 2 appear more than 3/n, since 3*(3/n+1) > n
        int n1 = 0, n2 = 0, cnt1 = 0, cnt2 = 0, n = nums.size();
        
        // search two candidates
        for (int i = 0; i < n; ++i) {
            if (nums[i] == n1) {
                ++cnt1;
            } else if (nums[i] == n2) {
                ++cnt2;
            } else if (cnt1 == 0) { // update n1
                n1 = nums[i];
                ++cnt1;
            } else if (cnt2 == 0){ // update n2
                n2 = nums[i];
                ++cnt2;
            } else {
                --cnt1;
                --cnt2;
            }
        }
        
        // check two candidates
        cnt1 = 0;
        cnt2 = 0;
        for (auto num : nums) {
            if (num == n1)
                ++cnt1;
            else if (num == n2)
                ++cnt2;
        }
        
        if (cnt1 > n/3)
            ret.push_back(n1);
        if (cnt2 > n/3)
            ret.push_back(n2);
        
        return ret;
    }
};
