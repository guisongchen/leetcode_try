/*

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/


class Solution {
public:
    int countPrimes(int n) {
        // find a prime i, mark all i*n as non-prime
        // then find the next prime j(the first unmark num), mark all j*n as non-prime
        // until n
        int cnt = 0;
        // non-prime make as false, in fact mark[0] and mark[1] are false
        // since we start from 2, mark[1] has no effect with result
        vector<bool> mark(n, true); 
        for (int i = 2; i < n; ++i) {
            if (mark[i]) {
                
                ++cnt;
                
                // j = 1, i*j = i, nonsense
                for (int j = 2; i*j < n; ++j) {
                    mark[i*j] = false;
                }
            }
        }
        
        return cnt;
    }
};
