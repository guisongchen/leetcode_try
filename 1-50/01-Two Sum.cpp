/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // keypoint: <value, idx>
        unordered_map<int, int> hash;
        const int N = nums.size();     
        vector<int> res;
        res.reserve(2);
        
        for (int i = 0; i < N; i++) {
            auto it_x2 = hash.find(target - nums[i]);
            
            // make sure find one, and find unique one
            if (it_x2 == hash.end()) {
                hash.emplace(nums[i], i);
            } else {
                res.push_back(i);
                res.push_back(it_x2->second);
                return res;
            }
        }
        
        return res;
    }
};
