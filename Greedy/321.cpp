class Solution {
public:
    vector<int> merge(vector<int> arr1, vector<int> arr2) {
        if(arr1.size() == 0) return arr2;
        if(arr2.size() == 0) return arr1;
        int m = arr1.size();
        int n = arr2.size();
        int l = 0, r = 0; // l for arr1 and r for arr2
        vector<int> res(m+n);
        int k = 0;
        while(k < res.size()){
            if(l == m or r != n and arr2[r] > arr1[l]) {
                res[k++] = arr2[r++];
            } else if(r == n or arr1[l] > arr2[r]) {
                res[k++] = arr1[l++];
            } else {
                int i = l, j = r;
                while(i < m && j < n) {
                    if(arr1[i] != arr2[j]) break;
                    i++; j++;
                }
                if(i == m or j == n) {
                    if(i != m)
                        res[k++] = arr1[l++];
                    else
                        res[k++] = arr2[r++];
                }
                else if(arr1[i] > arr2[j]) {
                    res[k++] = arr1[l++];
                } else
                    res[k++] = arr2[r++];
            }
        }
        return res;
    }
    vector<int> generate(vector<int>& nums, int L) {
        int n = nums.size();
        int drop = n-L;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            while(drop > 0 && ans.size() > 0 && ans.back() < nums[i]) {
                drop--;
                ans.pop_back();
            }
            ans.push_back(nums[i]);
        }
        ans.resize(L);
        return ans;
    }
    void compare(vector<int>& res,  vector<int> arr) {
        int l = 0;
        while(l < res.size() && res[l] == arr[l]) l++;
        if(l < res.size()) {
            if(res[l] < arr[l])
                res = arr;
        }
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k);

        for(int i = 0; i <= k; i++) {
            if(i <= nums1.size() && k-i <= nums2.size())
                compare(res, merge(generate(nums1, i), generate(nums2,k-i)));
        }
        return res;
    }
};
