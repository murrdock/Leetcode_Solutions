class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> s;
        s.insert(0);
        vector<bool> visit(rooms.size(), false);
        while(s.size()) {
            int t = *s.begin();
            s.erase(s.begin());
            if(visit[t]) continue;
            visit[t] = true;
            for(auto a : rooms[t]) {
                if(!visit[a]) {
                    s.insert(a);
                }
            }
        }
        for(int i = 0; i < visit.size(); i++) {
            if(!visit[i]) return false;
        }
        return true;
    }
};
