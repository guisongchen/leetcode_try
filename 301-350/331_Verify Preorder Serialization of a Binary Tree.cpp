/*

One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:

Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:

Input: "1,#"
Output: false
Example 3:

Input: "9,#,#,1"
Output: false

*/

// keypoints: 
// 1. '#' should be one more than digits
// 2. last character must be '#'

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // keypoints: 
        // 1. '#' should be one more than digits
        // 2. last character must be '#'
        
        istringstream input(preorder);
        string str;
        vector<string> st;
        while (std::getline(input, str, ','))
            st.push_back(str);
        
        // last character must be '#'
        if (st.back() != "#")
            return false;
        
        int cnt = 0; // cnt = signCnt - digitCnt
        
        // since last char is '#', we skip last character, search range: [0, n-2]
        // cnt >=0 when from 0 to n-1
        for (int i = 0, n = st.size(); i < n-1; ++i) {
            if (st[i] == "#") {
                if (cnt == 0) // less signs than digits 
                    return false;
                --cnt;
            } else {
                ++cnt;
            }
        }
        
        return cnt == 0;
    }
};
