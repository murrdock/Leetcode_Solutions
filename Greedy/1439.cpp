class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        priority_queue<int> pq;
        for(int i = 0; i < min(k, n); i++) { // first row
            pq.push(mat[0][i]);
        }
        for(int i = 1; i < m; i++) {

            priority_queue<int> pq_new; // holding k smallest possible sums till i-th row

            while(!pq.empty()) {

                int e = pq.top(); pq.pop();

                for(int j = 0; j < min(k, n); j++) {

                    pq_new.push(e+mat[i][j]);

                    if(pq_new.size() > k) {
                        if(pq_new.top() == e + mat[i][j]) { // only smaller elements are needed
                            pq_new.pop();
                            break;
                        }
                        pq_new.pop();
                    }
                }

            }

            pq.swap(pq_new);
        }

        return pq.top();
    }
};
