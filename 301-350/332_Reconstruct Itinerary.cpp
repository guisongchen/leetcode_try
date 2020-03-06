/*

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
             
*/



class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // graph traverse
        // use hash table to storage departure airport and multiset to storage arrival airport
        vector<string> ret;
        unordered_map<string, multiset<string>> hash;
        for (auto it : tickets) {
            hash[it[0]].insert(it[1]);
        }
        
        dfs(hash, ret, "JFK");
        
        // reverse to get right order
        return vector<string>(ret.rbegin(), ret.rend());
    }
    
    void dfs(unordered_map<string, multiset<string>>& hash, vector<string>& ret, string str) {
        
        if (hash[str].empty()) {
            ret.push_back(str);
            return;
        }
        
        while (!hash[str].empty()) {
            
            // using the beginner(small one), erase from hash
            string next = *(hash[str].begin());
            hash[str].erase(hash[str].begin());
            dfs(hash, ret, next);
        }
        
        ret.push_back(str);
    }
};
