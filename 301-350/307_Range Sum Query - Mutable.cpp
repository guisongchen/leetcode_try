/*

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.

*/



class NumArray {
public:
    NumArray(vector<int>& nums) {
        if (!nums.empty())
            cp.assign(nums.begin(), nums.end());
    }
    
    void update(int i, int val) {
        cp[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; ++k)
            sum += cp[k];
        return sum;
    }
    
private:
    vector<int> cp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
