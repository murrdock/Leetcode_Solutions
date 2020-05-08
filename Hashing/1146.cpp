#include <bits/stdc++.h>

using namespace std;

class SnapshotArray {
    map<int,int> ve;
    vector<map<int,int>> s;
public:
    SnapshotArray(int length) {
        //ve.resize(length);
    }

    void set(int index, int val) {
        ve[index] = val;
    }

    int snap() {
        s.push_back(ve);
        return s.size()-1;
    }

    int get(int index, int snap_id) {
        return s[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
