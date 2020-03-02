/*

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]

*/

// keypoints:
// 1. use dfs
// 2. notice corner cases: 010
// 3. add "." after each segment except last one


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // dfs
        vector<string> ret;
        string cur;
        dfs(s, ret, cur, s.size(), 0);
        return ret;
    }
    
    void dfs(string& s, vector<string>& ret, string& cur, int remain, int cnt) {
        
        // all digit from s are used
        if (cnt >= 4) {
            if(cnt == 4 && remain == 0){
                ret.push_back(cur);
            }
            
            return;
        }
            
        string backup = cur;
        
        for (int i = 1; i < 4; i++) {

            // substr needs to be checked
            string tmp = s.substr(cur.size()-cnt, i);

            if (checkRange(tmp)) {
                
                if (cnt != 3)
                    cur += tmp + ".";
                else  // the last part NOT need '.'
                    cur += tmp;
                
                dfs(s, ret, cur, remain-i, cnt+1);
                cur = backup;
            }
        }
    }
    
    bool checkRange(string& s) { 
        // corner case: 010
        if (s.size() > 1 && s[0] == '0')
            return false;
        
        int res = atoi(s.c_str());
        return res >= 0 && res <= 255;
    }
};
