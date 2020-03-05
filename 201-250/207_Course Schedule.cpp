/*

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

*/

// keypoints:
// 1. it is a graph problem, we should know the concept about indegree and outdegree of graph
// 2. if indegree == 0, means we can take this course(no prerequisites exist)
// 3. traverse input prerequistes to build indegree and outdegress(supplyChain) matrix
// two choises:
// 1st. dfs & visit matrix
  //    0: non-visited(init state); 1: checked(ok); -1: current used in recursive loop(revisited it means conflict)
// 2nd. bfs & candidates queue



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // use topological sort via bfs
        if (numCourses <= 1 || prerequisites.empty())
            return true;
        
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> supplyChain(numCourses);
        
        // update inDegree and reqChain
        for (auto req : prerequisites) {
            // req[0] is target course, req[1] is prerequisites
            // means req[1] server as supplier of req[0]
            supplyChain[req[1]].push_back(req[0]);
            ++inDegree[req[0]]; // required supplier cnt
        }
        
        // if the inDegree of course is 0, means it's valid, able to be used as pre..
        queue<int> valid;
        for (int i = 0; i < numCourses; ++i) {
            if (!inDegree[i]) {
                valid.push(i);
            }
        }
         
        // use valid course to solve reqChain
        while (!valid.empty()) {
            int cur = valid.front();
            valid.pop();
            
            // i is custom of cur
            for (auto i : supplyChain[cur]) {
                --inDegree[i]; // every vetex consider cur as supplier now satisfied
                if (inDegree[i] < 1) { // if all satisfied, then valid
                    valid.push(i);
                }
            }
        }
        
        for (auto vet : inDegree) {
            if (vet)
                return false;
        }

        return true;
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // use topological sort via dfs
        if (numCourses <= 1 || prerequisites.empty())
            return true;
        
        // use visit matrix instead of indegree to do dfs
        // 0: non-visited; 1: checked(ok); -1: current used(revisited it means conflict)
        vector<int> visited(numCourses, 0);
        vector<vector<int>> supplyChain(numCourses);
        
        // update inDegree and reqChain
        for (auto req : prerequisites) {
            // req[0] is target course, req[1] is prerequisites
            // means req[1] server as supplier of req[0]
            supplyChain[req[1]].push_back(req[0]);
        }
        
        for (int i = 0; i < numCourses; ++i) {
            // at least one target can't be satisfied by current course i
            if (!dfs(supplyChain, visited, i))
                return false;
        }
        
        return true;
    }
    
    // check preReq i satisfied all its custom or not
    bool dfs(vector<vector<int>>& supplyChain, vector<int>& visited, int i) {
        if (visited[i] == -1)
            return false;
        else if (visited[i] == 1)
            return true;
        
        // now visited[i] == 0, suppose we used i
        visited[i] = -1;
        
        // if all custom are satisfied, 
        for (auto custom : supplyChain[i]) {
            if (!dfs(supplyChain, visited, custom))
                return false;
        }
        
        // if not return means all custom is satified
        // which means only part of graph(start from i) is checked
        // update visited status
        visited[i] = 1;
        return true;
    }
};
