/*

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // try hashmap
        if (nums.size() < 2)
            return vector<int>{};
        
        unordered_map<int, int> hash;
        for (auto num : nums) {
            if (hash.count(num)) {
                --hash[num];
            } else {
                hash[num] = 1;
            }
        }
        
        vector<int> ret;
        for (auto it : hash) {
            if (it.second == 1)
                ret.push_back(it.first);
        }
        
        return ret;
    }
};
