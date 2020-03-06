/*

Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

Example:

Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
             super ugly numbers given primes = [2,7,13,19] of size 4.
Note:

1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

*/


// keypoints:
// 1. 1 is super Ugly number
// 2. set idx for each prime
// 3. nums[idx]*prime[idx], search minmum value as new prime(avoid duplicate)
// 4. push new super ugly number into result
// 5. increase idx we use last step
// 6. stop when we get n numbers

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> idx(k, 0);
        vector<int> nums({1});
        
        while (nums.size() < n) {
            int cur = INT_MAX;
            for (int i = 0; i < k; ++i) {
                cur = min(cur, nums[idx[i]] * primes[i]);
            }
            
            nums.push_back(cur);
            
            for (int i = 0; i < k; ++i) {
                if (cur == nums[idx[i]] * primes[i])
                    ++idx[i]; // may update more than one index, NOT use break
            }
        }
        
        return nums.back();
    }
};
