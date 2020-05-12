class RandomizedCollection {
public:
    multiset<int> s;
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val) == s.end()) {
            s.insert(val);
            return true;
        }
        s.insert(val);
        return false;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(s.find(val) == s.end()) {
            return false;
        }
        s.erase(s.lower_bound(val));
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int x = rand()%s.size();

        auto it = next(s.begin(), x);
        return *it;
    }
};
