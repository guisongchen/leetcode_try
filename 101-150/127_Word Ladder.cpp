/*

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/



class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // keypoint is use bfs
        // 1. which character transform first?
        // -> use bfs start from the first one, find candidates
        //    each candidates can also start from 0 to end
        // 2. this character trans. to what?
        // -> use bfs start from 'a' to 'z'
        // 3. how to speed up search in wordlist?
        // -> trans. into hash table
        
        unordered_set<string> hashSet(wordList.begin(), wordList.end());
        
        // corner case
        if (!hashSet.count(endWord))
            return 0;
        
        // keep candidates(at least one character same)
        queue<string> candidates;
        candidates.push(beginWord);
        
        // save wordPath by remember layer num
        // string at same layer were added after last layer
        // so remember last layer cnt and do circle until decrease to 0
        // then move to next layer
        int cnt = 0;
        
        // trace candidates match times
        /*
        unordered_map<string, int> wordPath;
        wordPath.insert({beginWord, 1});
        */
        
        // traverse each candidate
        while (!candidates.empty()) {
            cnt++;
            int cur = candidates.size();
            for (int k = 0; k < cur; k++) {
            
                string word = candidates.front();
                candidates.pop();
                
                // search for candidates, bfs start from idx 0
                for (int i = 0, n = word.size(); i < n; i++) {     
                    string newWord = word;
                    for (char j = 'a'; j <= 'z'; j++) {
                        newWord[i] = j;       
                        if (hashSet.count(newWord)) {
                            if (newWord == endWord) {
                                return ++cnt;
                            } else {
                                candidates.push(newWord);
                                hashSet.erase(newWord); // erase to decrease duplicate
                            }
                        }
                    }
                }
            }   
        }
        
        return 0;
        
    }
};
