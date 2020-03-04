/*

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/

// keypoints: 
// 1. prime > 1 && only divisible by 1 and itself
// 2. find the first prime i, then mark all n*i as non-prime(n >= 2) 
// 3. the first one un-marked is prime j, then mark all n*j as non-prime(n >= 2) 
// 4. do the loop

class Solution {
public:
    int countPrimes(int n) {
        // find a prime i, mark all i*n as non-prime
        // then find the next prime j(the first unmark num), mark all j*n as non-prime
        // until n
        int cnt = 0;
        // non-prime mark as false
        // since prime > 1, we start from 2
        vector<bool> isPrime(n, true); 
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                
                ++cnt;
                
                // j = 1, i*j = i, nonsense
                for (int j = 2; i*j < n; ++j) {
                    isPrime[i*j] = false;
                }
            }
        }
        
        return cnt;
    }
};
