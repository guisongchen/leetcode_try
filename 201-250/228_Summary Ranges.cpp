/*

Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.

*/


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return vector<string>{};
        
        vector<string> ret;
        int start = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            // if next integer is continuous with cur, skip safely
            // start idx was update at prev iter so no need worry, safe
            // use i != n-1 in case nums[i+1] overflow
            if (i != n-1 && nums[i]+1 == nums[i+1])
                continue;
            
            // now nums[i]+1 != nums[i+1]
            
            // if (start == i)
            // this iteration: start == i  -->  last iteration: start = i-1 + 1,
            // means nums[i-1]+1 != nums[i],  since now nums[i]+1 != nums[i+1]
            // so nums[i] is single
            
            // if (start != i) --> nums[i-1] + 1 = nums[i]
            // so start from nums[start] to nums[i]
            
            if (start == i) // which means nums[i] != nums[i-1]+1
                ret.push_back(to_string(nums[i]));
            else // nums[i] == nums[i-1] && nums[i] != nums[i+1]
                ret.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            
            // update start idx for next iteration
            start = i+1;
        }
        
        return ret;
    }
};
