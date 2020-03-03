/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/


// keypoints:
// use O(k) solution, update in place
// keypoint is iterative from end to begin
// because transform equation is  cur[j] = prev[j] + prev[j-1]; which is trival and use more space
// now we discard prev array, only use cur array, since cur array is updated every iteration, how to get last iteration value?
// --> since we use last iteration j-1 and j here
// --> if we update from end to begin,  we can use last iteration value before it updated


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // keypoint: use info from prev row
        if (rowIndex < 0)
            return vector<int>{};
        
        vector<int> prev;
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> cur(i+1, 1);
            if (i > 1) {
                for (int j = 1; j < i; j++)
                    cur[j] = prev[j] + prev[j-1];
            }
            
            prev.assign(cur.begin(), cur.end());
        }
        
        return prev;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // keypoint: use info from prev row
        if (rowIndex < 0)
            return vector<int>{};
        
        // use O(k) solution, update in place
        // keypoint is iterative from end to begin
        // because transform equation is  cur[j] = prev[j] + prev[j-1];
        // we get j-1 here, from end to begin we can use correct value before it updated
        vector<int> cur(rowIndex+1, 0);
        cur[0] = 1;
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--)
                cur[j] = cur[j] + cur[j-1];
        }
        
        return cur;
    }
};
