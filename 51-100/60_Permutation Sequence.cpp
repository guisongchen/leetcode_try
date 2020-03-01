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

// keypoints:
// 1. find the rule:

/*
a1 = k / (n - 1)!
k1 = k

a2 = k1 / (n - 2)!
k2 = k1 % (n - 2)!
...

an-1 = kn-2 / 1!
kn-1 = kn-2 % 1!

an = kn-1 / 0!
kn = kn-1 % 0!
*/

// 2. translate index to array index(which start from 0)

class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        string nums = "123456789";
        vector<int> factor(n, 1);
        
        // get directory of n!
        // get nums from 1 to n
        for (int i = 1; i < n; i++) {
            factor[i] = factor[i-1] * i;
        }
        
        // factor start from 0, while k>=1, turn k into array index by k-- 
        // also because we use '/' and '%' later, which all start from 0
        // so k MUST start from 0
        k--;
        
        for (int i = n; i >= 1; i--) {
            
            // for the i-th digit, it has (i-1)! permutations
            // which forms: i * (i-1)! permutation
            // locate i-th idx by divide (i-1)!
            int idx = k / (factor[i-1]);
            
            // after (n-1)! permutations, remian: k' = k % (factor[i-1])
            // update for next loop
            k =  k % (factor[i-1]);
            
            // push into result
            ret.push_back(nums[idx]);
            // erase chosen digit from nums
            nums.erase(idx, 1);
            
        }
        
        return ret;
    }
};
