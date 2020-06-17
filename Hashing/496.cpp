class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> s;
        for(int i = 0; i < nums2.size(); ){
            if(s.empty()) { s.push(i); i++; }
            else if(nums2[i] > nums2[s.top()]){
                m[nums2[s.top()]] = nums2[i]; s.pop();
            } else {
                s.push(i); i++;
            }
        }
        vector<int> res(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            res[i] = m[nums1[i]];
        }
        for(auto &x : res) if(x == 0) x = -1;
        return res;
    }
};
