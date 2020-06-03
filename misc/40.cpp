#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  inline string transform(vector<int>& t) {
      string ans = "";
      for(auto x : t) ans += to_string(x);
      return ans;
  }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int a = (1 << nums.size())-1;
        map<string, vector<int>> m;

        vector<vector<int>> ans;
        for(int j = a; j > 0; j = (j-1)&a) {
            bitset<31> b(j);
            vector<int> t;
            int sum = 0;
            for(int i = 0; i < 31; i++) {
                if(b.test(i)) {
                    sum += nums[i];
                    t.push_back(nums[i]);
                    if(sum > target) break;
                }
            }
            if(sum == target) {
                m[transform(t)] = t;
            }
        }
        for(auto it = m.begin(); it != m.end(); ++it) {
          ans.push_back(it->second);
        }
        return ans;
    }
};

int main() {
  int n; cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Solution ob;
  int target; cin >> target;
  vector<vector<int>> ans = ob.combinationSum2(arr, target);
  for(auto arr : ans) {
    for(auto x : arr) cout << x << " ";
    cout <<endl;
  }
  return 0;
}
