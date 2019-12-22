/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // hints:https://www.cnblogs.com/iCodingLife/p/8365196.html
        // divide and conquer
        //   index: 0 1 2 3 4 5
        //              | <- cut_1 = n1/2
        //           l1 | r1
        // array 1: 1 2 3 4 5
        // array 2: 3 4 5 6 7 8 
        //               | <- cut_2 = k - n1/2, k= k-th digit in two sorted arrays
        //            l2 | r2
        // require: l1 < r2 && l2 < r1 (l1 < r1, l2 < r2 are obvious since sorted)
        //
        // for median case, l1 + l2 = n1 + n2 / 2
        // mid = (max(l1+l2) + min(r1+r2))/2
        
        // since cut_1 + cut_2 = (n1+n2)/2, we choose short array to tune
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // by changing startOfN1 and endOfN1, we can change cut_1
        int startOfN1 = 0;
        int endOfN1 = n1;
        
        while (startOfN1 <= endOfN1) {
            
            // since we tune cut_1, init as (startOfN1 + endOfN1)/2
            int cut_1 = (startOfN1 + endOfN1)/2;
            int cut_2 = (n1 + n2)/2 - cut_1;
            
            // if move to left end, set l1 as negative big num to make sure max(l1,l2) = l2
            // | <-cut_1
            // 0 1 2 3 4 5 <-index of array 1
            //
            // if move to right end, set r1 as positive big num to make sure min(r1,r2) = r2
            //           | <-cut_1
            // 0 1 2 3 4 5 <-index of array 2
            
            int l1 = (cut_1 == 0) ? INT_MIN : nums1[cut_1 - 1];
            int r1 = (cut_1 == n1) ? INT_MAX : nums1[cut_1];
            
            // similar to l1, r1
            int l2 = (cut_2 == 0) ? INT_MIN : nums2[cut_2 - 1];
            int r2 = (cut_2 == n2) ? INT_MAX : nums2[cut_2];
            
            // NOTE: if we want increase cut_1, increase startOfN1(NOT reduce endOfN1)
            //       if we want reduce cut_1, reduce endOfN1(NOT increase startOfN1)
            //       DO NOT miss startOfN1 and endOfN1
            if (l1 > r2) {
                endOfN1 = cut_1 - 1;
            } else if (l2 > r1) {
                startOfN1 = cut_1 + 1 ;
            } else {
                if ((n1+n2)%2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return min(r1, r2);
                }
            }
        }
        
        return -1;
        
    }
};
