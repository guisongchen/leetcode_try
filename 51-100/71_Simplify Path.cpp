/*
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
*/


class Solution {
public:
    string simplifyPath(string path) {
        // basic rules:
        // 1. "/////" -> '/'   
        // 2. "/./" -> '/' 
        // 3. "/a/../" -> '/' (move back)
        
        // canonical path has no '.' or "..", only '/' and character
        // step 1: seperate chars between /''
        // step 2: handle special case like '.' or ".."
        
        // null case
        if (path.size() == 0)
            return path;
        
        int n = path.size();
        vector<string> buff;
        int i = 0;
        while (i < n) {
            // first char must be '/'
            // corner case "////"
            
            // locate start of chars
            // i < n put ahead to petect path[]
            while (i < n && path[i] == '/')
                i++;
            if (i == n)
                break;
            int start = i;
            
            while (i < n && path[i] != '/')
                i++;
            
            // note: i is '/', i-1 is end
            int end = i-1;
            
            // seperate is done here
            string temp = path.substr(start, end-start+1);
            
            // parse
            if (temp == ".") {
                i++;
            } else if (temp == "..") {
                if (!buff.empty()) {
                    buff.pop_back();
                }
                i++;
            } else {
                buff.push_back(temp);
                i++;
            }
        }
        
        if (buff.empty())
            return "/";
            
        string ret;
        for (int i = 0, m = buff.size(); i < m; i++)
            ret += "/" + buff[i];
        
        return ret;
    }
};
