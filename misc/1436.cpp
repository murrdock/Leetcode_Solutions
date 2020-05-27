class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        vector<string> arr;
        for(int i = 0; i < paths.size(); i++) {
            arr.push_back(paths[i][0]);
        }
        sort(arr.begin(), arr.end());
        auto it = unique(arr.begin(), arr.end());
        arr.resize(distance(arr.begin(), it));

        for(int i = 0; i < paths.size(); i++) {
            if(!binary_search(arr.begin(), arr.end(), paths[i][1])) {
                return paths[i][1];
            }
        }
        return " ";
    }
};
