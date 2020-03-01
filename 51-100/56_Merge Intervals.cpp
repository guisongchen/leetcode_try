/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

// keypoints:
// 1. notice intervals only consist two numbers, so we can sort by first, then compare the second

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2)
            return intervals;
        
        vector<vector<int>> ret;
        
        // use lamda is much slower, why?
        sort(intervals.begin(), intervals.end());
        
        // after  sort, we put first elments in
        ret.emplace_back(intervals[0]);
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            // MUST use merged array do the compare
            if (ret.back()[1] >= intervals[i][0]) {
                ret.back()[1] = max(ret.back()[1],intervals[i][1]);
            } else {
                ret.emplace_back(intervals[i]); 
            }
        }
        
        return ret;
    }
};
