/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/



// keypoints:
// 1. use greedy algorithm
// 2. transform formular:  reach = max(reach, i+nums[i])
//    reach: max reachable index(aka skip index i)
//    i+nums[i] : start from index i

// corner case:
// 1. i > reach, means can't reach index i, which means false
// 2. reach >= n-1, means we can reach ending, should be true
//    using ">=" means equal or beyond ending both are true

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Greedy
        int n = nums.size();
        int reach = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i > reach || reach >= n-1)
                return reach >= n-1;
            reach = max(i+nums[i], reach);
        }
        
        return reach >= n-1;
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Greedy
        
        // we stand at the end, want to prove we can reach the beginning
        // why at the end?
        // --> we should start from begin(left) to end()right, if we meet nums[i] == 0
        //     which means we are stucked, we hope some elements at left help us jump this
        //     since our helper stay at left, we must start from right to left,
        //     so we have chance to verify.
        int pos = nums.size()-1;
        for (int i = nums.size()-1; i >= 0; i--) {
            // be greedy, we use all nums[i] each time
            // if successed, move forward, update pos we stand;
            if (i + nums[i] >= pos)
                pos = i;
        }
        
        // whether we get the end or not
        return pos == 0;
    }
};
