/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // null case or single digit
        if (nums.size() < 2)
            return;
        
        // step1: find the first decrease(or equal) pos from end as startPos of switch
        // if not exist, then nums is a decrease array(e.g. 3,2,1)
        // we set startPos = -1 and value = INT_MIN
        // NOTE: DO NOT FORGET break
        int startPos = -1;
        const int n = nums.size();
        for (int i = n-1; i>=0; i--) {
            // NOTE: DO NOT use equal here, if equal then nothing change
            if (i>0 && nums[i-1] < nums[i]) {
                startPos = i-1;
                break;
            }
        }
            
        // step2: sort form next idx after startPos(increasing order)
        // cornen case:
        // if startPos < 0, sort form begin() and return
        // others sort form next of startPos
        if (startPos < 0) {
            sort(nums.begin(), nums.end());
            return;
        } else {
            sort(nums.begin()+startPos+1, nums.end());
        }
        
        // step3: find the first Pos which value big than startPos value
        //        swap with startPos value
        const int tar = nums[startPos];
        for (int i = startPos+1; i < n; i++) {
            
            // NOTE: NOT use equal here, if equal then nothing change
            if (nums[i] > tar) {
                // NOTE:DO NOT FORGET break
                nums[startPos] = nums[i];
                nums[i] = tar;
                break;
            }
        }
    }
};
