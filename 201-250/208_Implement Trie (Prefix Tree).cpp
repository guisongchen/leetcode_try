/*

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

*/

// keypoints:
// 1. using next[] to keep link to next character
// 2. using isLeaf to determine whether pointer reach the ending of word or not.
// 3. delete after new operate


class Trie {
public:
    /** Initialize your data structure here. */
    
    Trie() : isLeaf(false) {}
    ~Trie() {
        for (int i = 0, n = nodes.size(); i < n; ++i)
            delete nodes[i];
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (!cur->next[idx]) {
                cur->next[idx] = new Trie();
                nodes.push_back(cur->next[idx]);
            }
            cur = cur->next[idx];
        }
        
        cur->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (cur->next[idx])
                cur = cur->next[idx];
            else
                return false; // not break, return( break may return true, like:ab aba)
        }
        
        return cur->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (int cnt = 0, n = prefix.size(); cnt < n; ++cnt) {
            int idx = prefix[cnt] - 'a';
            if (cur->next[idx])
                cur = cur->next[idx];
            else
                return false;
        }
        
        return true;
    }
    
private:
    Trie* next[26] = {};
    vector<Trie*> nodes;
    bool isLeaf;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
