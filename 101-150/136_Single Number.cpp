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

// solutions:
// 1. double pointer, compare two number each time
// 2. hashMap, first insert, second erase, final exist one is result
// 3. XOR of all numbers, result is single number value

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


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // first idea is sort and double pointer
        // O(NlogN)
        if (nums.size() == 1)
            return nums[0];
        
        sort(nums.begin(), nums.end());
        
        // notice we compare 2 at one time and skip two to avoid duplicated num
        for (int i = 0, n = nums.size(); i < n-1; i += 2) {
            if (nums[i] != nums[i+1]) {
                // maybe i or i+1
                if (i == 0) {
                    return nums[i];
                } else {
                    return nums[i-1] == nums[i] ? nums[i+1] : nums[i];
                }
            }
        }
        
        // if not return before, must be the last one
        return nums.back();
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums) {
            if (st.count(num)) st.erase(num);
            else st.insert(num);
        }
        return *st.begin();
    }
};
