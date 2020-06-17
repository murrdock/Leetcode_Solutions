class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<int> visit(nums.size(), false);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(!visit[i]){
                int c = 1;
                visit[i] = true;
                int next = nums[i];
                while(next != i){
                    c++;
                    visit[next] = true;
                    next = nums[next];
                }
                ans = max(ans, c);
            }
        }
        return ans;
    }
};
