/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

*/

// keypoints:
// 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int left = 0, right = height.size()-1; left < right;) {
            int hl = height[left];
            int hr = height[right];
            int area = (right-left) * min(hl, hr);
            
            if (area > max)
                max = area;
            if (hl > hr) {
                right--;
            } else {
                left++;
            }
        }
        
        return max;
    }
};
