/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/


class Solution {
public:
    string getPermutation(int n, int k) {
        string ret(n, '1');
        vector<int> nums(n, 1);
        vector<int> factor(n, 1);
        
        // get directory of n!
        // get nums from 1 to n
        for (int i = 1; i < n; i++) {
            factor[i] = factor[i-1] * i;
            // i from 0 to n-1, nums[i] form 1 to n
            nums[i] = i + 1;
        }
        
        // factor start form 0, while k>=1, aligned by k--
        // also because we use '/' and '%' later, which all start from 0
        // so k MUST start form 0
        k--;
        
        auto it_begin = nums.begin();
        for (int i = n; i >= 1; i--) {
            // for the i-th digit, it has (i-1)! permutations
            // which forms: i * (i-1)! permutation
            // locate i-th idx by divide (i-1)!
            int idx = k / (factor[i-1]);
            
            // push into result(update init '1' with num)
            // since k from 0 to n-1; n from 1 to n; k+'1' map to nums{1,2,3...}
            ret[n-i] = nums[idx] + '0';
            // erase chosen digit from nums
            nums.erase(it_begin+idx);
            
            // after (n-1)! permutations, remian: k' = k % (factor[i-1])
            // update for next loop
            k =  k % (factor[i-1]);
        }
        
        return ret;
    }
};
