#include <list>
#include <unordered_map>

using std::list;
using std::unordered_map;

class LRUCache {
  public:
    int cacheSize;
    list<int> cache;
    unordered_map<int, int> key2val;
    unordered_map<int, std::list<int>::iterator> key2Iter;
    LRUCache(int capacity) {

        cacheSize = capacity;
    }

    int get(int key) {
        if (key2val.find(key) == key2val.end())
            return -1;

        int k = *key2Iter[key];
        cache.erase(key2Iter[key]);
        cache.push_back(k);

        key2Iter[key] = std::prev(cache.end());
        return key2val[key];
    }

    void put(int key, int value) {
        if (cacheSize == 0)
            return;
        // check if already exist in cache
        if (get(key) != -1) {
            // exist modified the val
            key2val[key] = value;
            return;
        } else if (cache.size() == cacheSize) {
            // chech the size
            int remove_key = cache.front();
            key2val.erase(remove_key);
            key2Iter.erase(remove_key);
            cache.pop_front();
            // put the key into
        }
        // is not full
        key2val[key] = value;
        cache.push_back(key);
        key2Iter[key] = std::prev(cache.end());
    }
};
