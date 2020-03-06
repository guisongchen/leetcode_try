/*

For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1 :

Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

Output: [1]
Example 2 :

Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

Output: [3, 4]
Note:

According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

*/


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // keypoints:
        // 1. like peeling onion, we cut leaves off tree layer by layer, 
        //    remaining nodes will be root
        // 2. the root must be one node or two nodes, no other possibilities
        // 3. what makes a leaf ?
        // -> if has only one adjacency(adj size = 1), may be leaf, push into candidates queue
        // -> cut the leaf from candidates queue and its adjacencies, 
        //    check new leaf candidates exist or not
        // -> each time we pop candidates and update adjacency tables
        //    we skinning one layer from onion, the last remains will be root
        // -> if only one or two candidates exist, it will be root
        
        if (n == 1)
            return {0};
        
        vector<int> ret;
        // adjacency table of node i <i, adjacencies of i>
        vector<unordered_set<int>> adj(n);
        queue<int> cand; // candidates of root
        
        // update adjacency table
        for (int i = 0, m = edges.size(); i < m; ++i) {
            // edges[i][0] and edges[i][1] are adjacency of each other
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        
        // collect leaf candidates
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1)
                cand.push(i);
        }
        
        // check candidates, use down to top, skinning onion
        int remain = n;
        while (remain > 2) {
            
            int cnt = cand.size();
            remain -= cnt;
            
            while (cnt--) {
                int cur = cand.front();
                cand.pop();

                // cut cur leaf from its adjacencies
                for (auto it : adj[cur]) {
                    adj[it].erase(cur);
                    
                    // if new leaf candidate occur, push
                    if (adj[it].size() == 1)
                        cand.push(it);
                }
            }
        }
        
        // since we peel layer by layer, roots must be consider as leaf and push into queue
        // now we get them
        while (!cand.empty()) {
            ret.push_back(cand.front());
            cand.pop();
        }
        
        return ret;
    }
};
