/*

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

*/

class WordDictionary {
public:
    /** Initialize your data structure here. */

    WordDictionary() {}
    ~WordDictionary() {
        for (auto it : nodes)
            delete it;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* cur = this;
        for (int i = 0, n = word.size(); i < n; ++i) {
            int idx = word[i] - 'a';
            if (!cur->next[idx]) {
                cur->next[idx] = new WordDictionary();
                nodes.push_back(cur->next[idx]);
            }
            
            cur = cur->next[idx];
        }
        
        cur->isLeaf = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, this, 0);
    }
    
    bool dfs(string& word, WordDictionary* cur, int idx) {
        if (idx == word.size())
            return cur->isLeaf;
        
        if (word[idx] == '.') {
            for (auto ptr : cur->next) {
                if (ptr && dfs(word, ptr, idx+1)) {
                    return true;
                }
            }
            
            return false;
        } else {
            int id = word[idx] - 'a';
            if (!cur->next[id])
                return false;
            return dfs(word, cur->next[id], idx+1);
        }
        
        return true;
    }
private:
    WordDictionary* next[26] = {};
    bool isLeaf = false;
    vector<WordDictionary*> nodes;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
