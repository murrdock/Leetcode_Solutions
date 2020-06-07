class LRUCache {
public:
    int n;
    list<pair<int,int>> l; // value, key
    unordered_map<int, list<pair<int,int>>::iterator> um;
    LRUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {
        if(um.find(key) == um.end()) return -1;
        auto it = um[key];
        int val = it->first;
        l.erase(it);
        l.push_front(make_pair(val, key));
        um[key] = l.begin();
        return val;
    }

    void put(int key, int value) {
        if(um.find(key) != um.end()) {
            get(key);
            l.begin()->first = value;
        } else {
            if(um.size() == n) {
                int k = l.back().second;
                auto it = um[k];
                l.erase(it);
                um.erase(k);
            }
            l.push_front(make_pair(value,key));
            um[key] = l.begin();
        }
    }
};
