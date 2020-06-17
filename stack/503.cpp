class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visit(n, false);
        vector<int> res(n, -1);
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && nums[i] > nums[s.top()]){
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for(int i = 0; i < n; i++){
            if(s.empty()) break;
            while(!s.empty() && nums[i] > nums[s.top()]){
                res[s.top()] = nums[i];
                s.pop();
            }
        }
        return res;
    }
};
