class Solution {
public:
    int parition(vector<int>& A, int p, int r){
    int key = A[p];
    int l = p;
    for(int j = p+1; j <= r; j++){
        if(A[j] <= key){
          l++;
          swap(A[l], A[j]);
        }
    }
    swap(A[l], A[p]);
    return l;
}
    int RFindRank(vector<int>& A, int l, int r, int k){
    if(l < r){
        int p = l + rand()%(r-l+1); // choosing pivot
        swap(A[l], A[p]);
        int x = parition(A,l,r);
        if( k == (r-x+1)){
            return A[x];
        }
        else if(k < (r-x+1)){
            return RFindRank(A, x+1, r, k);
        }
        else{
            return RFindRank(A, l, x-1, k-r+x-1);
        }
    }
    return A[l];
}
    int findKthLargest(vector<int>& nums, int k) {
        return RFindRank(nums, 0, nums.size()-1, k);
    }
};
