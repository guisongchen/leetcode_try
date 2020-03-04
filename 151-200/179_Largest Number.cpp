/*

Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.

*/


// keypoints:
// 1. order string
// 2. using string compare instead of int compare
// 3. keypoint is compare the combination of ab, not a and b, ab > ba then a is bigger

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // turn int into string, combian in ascending order
        vector<string> str;
        for (auto num : nums) {
            str.push_back(to_string(num));
        }
        
        // order string
        // keypoint is compare the combination of ab, not a and b
        // ab > ba then a is bigger
        // corner case: 30, 3;  12, 121
        sort(str.begin(), str.end(), 
            [] (string& a, string& b) { return a+b > b+a;} );
        
        string ret;
        for (auto s : str) {
            ret += s;
        }
        
        // corner case: 0, 0
        return ret[0] == '0' ? "0" : ret;
    }
};
