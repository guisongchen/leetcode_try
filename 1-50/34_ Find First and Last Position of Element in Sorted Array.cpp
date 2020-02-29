/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
// keypoint: binary search
// step1: find target Pos (caution: redudant case 8888888)
// step2: search left find first Pos
// step3: search right find last Pos

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // define retuen value
        //vector<int> ret{-1, -1};
        // null case
        if (nums.size() == 0)
            return vector<int> {-1, -1};
        
        // step1: find target Pos (caution: redudant case 8888888)
        // step2: search left find first Pos
        // step3: search right find last Pos
        const int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid;
        
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                
                int first = mid;
                // 0 ~ mid
                for (int i = mid-1; i >= 0; i--) {
                    if (nums[i] == target) {
                        first = i;
                    }
                }
                
                int last = mid;
                // mid ~ n-1
                for (int i = mid+1; i < n; i++) {
                    if (nums[i] == target) {
                        last = i;
                    }
                }
                
                return vector<int> {first, last};
                
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return vector<int> {-1, -1};
    }
};
