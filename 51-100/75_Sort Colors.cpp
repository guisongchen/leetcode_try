/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // insert sort
        for (int i = 1, n = nums.size(); i < n; i++) {
            int temp = nums[i];
            // compare to prevs
            int j = 0;
            for (j = i; j > 0; j--) {
                // if prev is big than nums[i], move to right
                if (nums[j-1] > temp) {
                    nums[j] = nums[j-1];
                } else {
                    break; // find the place for temp, temp > nums[j-1], should stay at j
                }
            }
            nums[j] = temp;
        }
    }
};
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // insert sort
        for (int i = 1, n = nums.size(); i < n; i++) {
            int temp = nums[i];
            // compare to prevs
            int j = 0;
            for (j = i; j > 0; j--) {
                // if prev is big than nums[i], move to right
                if (nums[j-1] > temp) {
                    nums[j] = nums[j-1];
                } else {
                    break; // find the place for temp, temp > nums[j-1], should stay at j
                }
            }
            nums[j] = temp;
        }
    }
};
