#include<bits/stdc++.h>

using namespace std;
/* Explanation
Store source to destination and average of time of travel between them in a hash_map.
Store id and corresponding information in map for chekcIn and checkOut.
Update the average as done in checkOut method.
*/
class UndergroundSystem {
public:
    map<int, pair<string,int>> ve;
    map<string, pair<double,int>> m;
    string transform(string a, string b) {
        return a + "-" + b;
    }
    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        ve[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t) {
        pair<double, int>& p = m[transform(ve[id].first, stationName)];
        p.first = p.first + t-ve[id].second;
        p.second += 1;
        ve.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        pair<double, int>& p = m[transform(startStation, endStation)];
        return p.first/p.second;
    }
};
