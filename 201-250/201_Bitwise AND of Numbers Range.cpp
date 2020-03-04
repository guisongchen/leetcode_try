/*

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0

*/

// keypoints: find the left common bits between m and n
// compare m and n bit by bit
// if m != n means current bit is not the same ('0' or '1')
// then nums form m to n, AND result at current bit must '0'(since already '0' exist)
// so shift m and n right, compare the next bit
// shift times are zero numbers on the right side
// current m is the left common bits(since m == n now)

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // use bit operator to speed up(from ++ to <<)
        // keypoint is find same bit squency of nums w.r.t m

        int zeroCnt = 0; // how may zero on the right side
        // compare m and n bit by bit
        // if m != n means current bit is not the same ('0' or '1')
        // then nums form m to n, AND result at current bit must '0'(since already '0' exist)
        // so shift m and n right, compare the next bit
        
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++zeroCnt; // how many zeros at right side
        }
        
        // shift left zeroCnt times to add '0' bits at right 
        return m << zeroCnt;
    }
};
