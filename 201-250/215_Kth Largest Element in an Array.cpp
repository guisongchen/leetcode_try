/*

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

*/


// keypoints:
// 1. quick sort
// 2. when elements <= 6, use insert sort
// 3. use median3 to get pivot
// 4. swap pivot and nums[right-1], left, right-1, right is sorted, unsorted range:[left+1, right-2]
// 5. when i = j, do not swap


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort is travial, use quick sort
        // best thing of quick sort, after each iteration, pivot will at right poistion
        int ret = 0, n = nums.size();
        quickSort(nums, 0, n-1, n-k);
        return nums[n-k]; // n-k must in the correct position
    }
    
    void quickSort(vector<int>& nums, int left, int right, int idx) {     
        // when unsorted num is small, use insert sort
        // at least has length 6
        if (right - left <= 6) {
            for (int i = left+1; i <= right; ++i) {
                int temp = nums[i];
                int j;
                for (j = i; j > left && nums[j-1] > temp; --j) {
                    nums[j] = nums[j-1]; 
                }
                // when jump out loop, nums[j] <= temp
                nums[j] = temp;
            }
            return;
        }
        
        // at least need 6 elements, otherwise will degenerated
        int pivot = median3(nums, left, right);
        int i = left; // use ++i below
        int j = right - 1; 
        
        // sort [left+1, right-2]
        while(1) {
            while (nums[++i] < pivot) {}
            while (nums[--j] > pivot) {}
            
            if (i < j)
                swap(nums[i], nums[j]);
            else
                break;
        }
        
        // update pos i, swap with pivot
        // i = j, use i or j is ok
        swap(nums[i], nums[right-1]);
        
        // if current pivot is kth largest
        if (i == idx)
            return;
        
        quickSort(nums, left, i-1, idx);
        quickSort(nums, i+1, right, idx);
    }
    
    
    // notice pivot lies in right-1, and left, right-1, right is sorted
    int median3(vector<int>& nums, int left, int right) {
        int center = left + (right-left) / 2;
        if (nums[left] > nums[center])
            swap(nums[left], nums[center]);
        if (nums[center] > nums[right])
            swap(nums[center], nums[right]);
        if (nums[left] > nums[center])
            swap(nums[left], nums[center]);
        // left and right are handled now, consider [left+1, right-1]
        // we swap center and right-1, so right-1 is sorted too
        // only needs to sort[left+1, right-2]
        swap(nums[center], nums[right-1]);
        return nums[right-1];
    }
};
