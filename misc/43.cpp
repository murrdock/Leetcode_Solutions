class Solution {
public:
    void convert(string &num, vector<int>& ve){
        for(int i = 0; i < num.length(); i++)
            ve.push_back(num[i]-'0');
    }
    vector<int> multy(int x, vector<int>& A){
        int carry = 0;
        vector<int> res(A.size()+1, 0);
        for(int i = res.size()-1; i > 0; i--){
            res[i] = (carry + x*A[i-1])%10;
            carry = (carry + x*A[i-1])/10;
        }
        res[0] = carry;
        return res;
    }

    void add(vector<int>& res, vector<int>& ve, int a){
        reverse(ve.begin(),ve.end());
        int carry = 0;
        for(int i = 0; i < ve.size(); i++){
            int z = (res[i+a]+ve[i]+carry);
            res[i+a] = z%10;
            carry = z/10;
        }
    }
    string multiply(string num1, string num2) {
        vector<int> x, y;
        convert(num1,x); convert(num2,y);
        string out = "";
        vector<int> res(x.size()+y.size());
        int a = 0;
        for(int i = y.size()-1; i >= 0; i--) {
            vector<int> ve = multy(y[i], x);
            add(res, ve, a);
            a++;
        }
        reverse(res.begin(),res.end());
        int i = 0;
        while(i < res.size() && res[i] == 0) i++;
        for(i; i < res.size(); i++)
            out += (char)('0'+res[i]);
        if(out == "") out = "0";
        return out;
    }
};
