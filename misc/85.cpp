class Solution {
private:
    int largestRectangleArea(vector<int>& A) {
        if(!A.size()) return 0;
        stack<int> s;
        s.push(0);
        int max_area = 0, area = 0;
        int i;
        for( i = 1; i < A.size();){
            if(s.empty() || A[i] > A[s.top()]){
                s.push(i);
                i++;
                continue;
            }
            int top = A[s.top()]; s.pop();
            if(s.empty()){
                area = top*i;
            }
            else{
                area = (i - s.top() -1)*top;
            }

            max_area = max(area, max_area);
        }
        while(!s.empty()){
            int top = A[s.top()]; s.pop();
            if(s.empty()){
                area = top*i;
            }
            else{
                area = (i - s.top() -1)*top;
            }

            max_area = max(area, max_area);
        }
        return max_area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        int max_area = 0;
        int area = 0;
        vector<int> A(matrix[0].size());
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                A[j] = matrix[i][j] == '0' ? 0 : A[j]+1;
            }
            area = largestRectangleArea(A);
            max_area = max(area, max_area);
        }
        return max_area;
    }
};
