
// using priority_queue queue, Max Heap
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
        int i;
        for(i = 0; i+1 < k; i++) {
            pq.push(make_pair(nums[i],i));
        }
        vector<int> ans;
        for(i; i < nums.size(); i++) {
            pq.push(make_pair(nums[i], i));

            while(pq.top().second <= i-k) pq.pop();

            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

// using deque maintaining increasing order

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i = 0; i < k; i++) {
            if(dq.empty()) {
                dq.push_back(i);
            }
            else if(nums[i] >= nums[dq.back()]) {
                dq.push_back(i);
            } else {
                while(nums[dq.front()] < nums[i]) dq.pop_front();
                dq.push_front(i);
            }
        }
        vector<int> ans;
        for(int i = k; i < nums.size(); i++) {
            ans.push_back(nums[dq.back()]);
            while(!dq.empty() && dq.back() <= i-k) dq.pop_back();
            if(dq.empty()) {
                dq.push_back(i);
            } else if(nums[i] >= nums[dq.back()]) {
                dq.push_back(i);
            } else {
                while(nums[dq.front()] < nums[i]) dq.pop_front();
                dq.push_front(i);
            }
        }
        ans.push_back(nums[dq.back()]);
        return ans;
    }
};
