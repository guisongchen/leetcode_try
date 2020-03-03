/*

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/



class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        
        // update frequency
        if (it != cache.end()) {
            touch(it); // if exist, update usedFreq, push to head
        } else {
            // if full. erase least recent used(back of usedFreq), update usedFreq
            if (cache.size() == capacity_) {
                cache.erase(usedFreq.back());
                usedFreq.pop_back();
            }
            
            // not full, push directly
            usedFreq.push_front(key);
        }
        
        // update cache info, touch() will move put key to the head
        cache[key] = {value, usedFreq.begin()};
    }
    
private:
    typedef unordered_map<int, pair<int, list<int>::iterator>> HashListIter;
        
    // push recent used key to head
    // 1. erase key element(which may not at head)
    // 2. push key to head
    // through erase and push_front make sure key(pointed by it) stay at head
    void touch(HashListIter::iterator it) {
        int key = it->first;
        // delete old iterator
        usedFreq.erase(it->second.second);
        // push front, update usedFreq
        usedFreq.push_front(key);
        
        // update cache
        it->second.second = usedFreq.begin();
    }
    
    // usedFreq is used to track frequency, decide which is erased when cache full
    // cache keep key and value, value is paired with frequency by iterator of usedFreq
    
    list<int> usedFreq; // sorted key by using frequency, from most to least recent
    HashListIter cache; // hash table of key and handle(handle is iterator of usedFreq)
    int capacity_;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
