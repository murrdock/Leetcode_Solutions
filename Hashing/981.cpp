class TimeMap {
public:
    unordered_map<string, map<int, string>> stamp;
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        stamp[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if(stamp.find(key) == stamp.end()) return "";
        map<int,string>& m = stamp[key];
        int t = timestamp;
        auto it = m.lower_bound(t);
        if(it == m.begin()) {
            if(it->first == t)
                return it->second;
            return "";
        }
        if(it == m.end()) {
            it = prev(it,1);
            return it->second;
        }
        if(it->first == t) return it->second;
        it = prev(it, 1);
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
