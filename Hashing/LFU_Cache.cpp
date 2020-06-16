class LFUCache {
    int n;
    using node = tuple<int,int,int>; // key, value, freq
    unordered_map<int, list<node>::iterator> um; // key , node pointer
    map<int, list<node>> F; // frequency , list of nodes with that frequency
public:
    LFUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {
        if(n == 0) return -1;
        if(um.find(key) == um.end()) return -1;

        auto it = um[key];

        int f = std::get<2>(*it);
        int val = std::get<1>(*it);

        F[f].erase(it);

        if(F[f].empty()) F.erase(f);

        f++;

        F[f].push_front(make_tuple(key, val, f));
        um[key] = F[f].begin();

        return val;
    }

    void put(int key, int value) {

        if(n == 0) return;
        if(um.size() == n) {

            if(um.find(key) == um.end()) {
                auto it = F.begin();

                um.erase(std::get<0>(it->second.back()));
                it->second.pop_back();

                if(it->second.empty())
                    F.erase(it->first);

            }
        }
        if(um.find(key) == um.end()) {
            F[1].push_front(make_tuple(key, value, 1));
            um[key] = F[1].begin();
        } else {
            get(key);
            std::get<1>(*um[key]) = value;
        }
    }
};
