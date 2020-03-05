/*

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]


 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

*/

// solution 1: recursive
// solution 2: dfs to find path1 and path2, then compare to find LCA

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // following code valid when p and q are sure exist
        // recursive is simple but not so intuitive
        
        // notice if p or q is root, then return itself
        if (!root || root == q || root == p)
            return root;
        
        // search left, return value may be null or p or q or some valid node
        // in fact, since p and q must exist, left and right can't be both null
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // search right, return value may be null or p or q or some valid node
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // since left and right both return non-null, they must return q or p
        if (left && right)
            return root;
        // since q or p must exist, so must one of left and right non-null
        // we should return non-null value
        return left ? left : right;
        
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // following code valid when p and q are sure exist
        // recursive is simple but not so intuitive
        // use dfs to find path of p and q, then compare to find LCA
        if (!root || root == q || root == p)
            return root;
        
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        
        dfs(root, path1, p);
        dfs(root, path2, q);
        
        int cnt = min(path1.size(), path2.size());
        TreeNode* ret = nullptr;
        for (int i = 0; i < cnt; ++i) {
            if (path1[i] == path2[i])
                ret = path1[i];
        }
        
        return ret;
    }
    
    bool dfs(TreeNode* cur, vector<TreeNode*>& path, TreeNode* tar) {
        if (!cur)
            return false;
        
        path.push_back(cur);
        
        if (cur == tar)
            return true;
        
        if (!dfs(cur->left, path, tar) && !dfs(cur->right, path, tar))
            path.pop_back();
        else
            return true;
        
        return false;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // following code valid when p and q are sure exist
        // recursive is simple but not so intuitive
        // use dfs to find path of p and q, then compare to find LCA
        if (!root || root == q || root == p)
            return root;
        
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        vector<TreeNode*> path;
        
        dfs(root, path, path1, path2, p, q);
        
        int cnt = min(path1.size(), path2.size());
        TreeNode* ret = nullptr;
        for (int i = 0; i < cnt; ++i) {
            if (path1[i] == path2[i])
                ret = path1[i];
        }
        
        return ret;
    }
    
    void dfs(TreeNode* cur, vector<TreeNode*>& path,
             vector<TreeNode*>& path1, vector<TreeNode*>& path2,
             TreeNode* p, TreeNode* q) {
        if (!cur)
            return;
        
        path.push_back(cur);
        
        if (cur == p)
            path1.assign(path.begin(), path.end());
        else if (cur == q)
            path2.assign(path.begin(), path.end());
        
        if (!path1.empty() && !path2.empty())
            return;
        
        dfs(cur->left, path, path1, path2, p, q);
        dfs(cur->right, path, path1, path2, p, q);
        
        path.pop_back();
    }
};

