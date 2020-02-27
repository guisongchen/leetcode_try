/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // need to consider this question in another way:
        // the two keywords are: longest and un-repeating
        // step 1: find distance between two repeating characters
        //         this distance is un-repeating distance
        // step 2: find the longest distance
        
        // step 1: find distance between repeating characters
        // how to do this efficiently?
        // --> use sliding window, characters in sliding window are un-repeated
        // how to construct a sliding window?
        // --> range ? 
        //     use left and right index to represent begin and end of window 
        // --> maintance ?
        //     use map to query state, keep un-repeat in 
        // --> distance ?
        //     distance = window size = right - left

        // left_prev is the prev position of left window range
        // since left range start from 0, left_prev init as -1
        // so if left_prev & right are same character, dist = right-left_prev
        // also consider corner case: if no-repeated
        // maxDist = s.size() = right - left + 1 = right - left_prev = N
        int left_prev = -1; 
        int maxDist = 0;
        int curDist = 0;
        char curChar;
        unordered_map<char, int> mp;
        
        for (int right = 0, N = s.size(); right < N; right++) {
            curChar = s[right];
            
            // if curChar already exist
            if (mp.count(curChar)) {
                // if curChar is in window, since we want no repeat in window
                // move left_prev to mp[curChar], aka we narrow the window
                // if curChar NOT in window, we are safe
                
                // make sure curChar in window, aka mp[curChar] > left_prev
                if (left_prev < mp[curChar])
                    left_prev = mp[curChar];
            }
                            
            // step 2: find the longest distance
            curDist = right - left_prev;
            if (curDist > maxDist)
                maxDist = curDist;
            
          // step 3: update map using curChar
            // map's key value can't be same.
            // throw every character we meet into map, since we use char as key value
            // if curChar exist, it will be update, if not, it will be added
            mp[curChar] = right;
        }
        
        return maxDist;
    }
};
