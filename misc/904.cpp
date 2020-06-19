class Window{
private:
    map<int,int> m;
public:
    Window() {}
    void add(int x) {
        m[x]++;
    }
    void remove(int x){
        m[x]--;
        if(m[x] == 0) m.erase(x);
    }
    int size(){
        return m.size();
    }
};

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int ans = 0;
        Window w;
        int l = 0;
        for(int i = 0; i < tree.size(); i++){
            w.add(tree[i]);
            while(w.size() > 2) {
                w.remove(tree[l++]);
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};
