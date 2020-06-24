class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void make_set(int v){
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v){
        if(v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        parent.resize(4*n*n);
        size.resize(4*n*n);
        for(int i = 0; i < 4*n*n; i++){
            make_set(i);
        }
        for(int i = 0; i < n; i++){
            string &s = grid[i];
            for(int j = 0; j < n; j++){
                if(s[j] == '/'){
                    union_sets(4*n*i+4*j+0,4*n*i+4*j+3);
                    union_sets(4*n*i+4*j+1,4*n*i+4*j+2);
                } else if(s[j] == '\\'){
                    union_sets(4*n*i+4*j+0,4*n*i+4*j+2);
                    union_sets(4*n*i+4*j+1,4*n*i+4*j+3);
                } else {
                    union_sets(4*n*i+4*j+0, 4*n*i+4*j+1);
                    union_sets(4*n*i+4*j+2, 4*n*i+4*j+3);
                    union_sets(4*n*i+4*j+1, 4*n*i+4*j+2);
                }
                if(i < n-1){
                    union_sets(4*n*(i+1)+4*j+0, 4*n*i+4*j+1);
                }
                if(j < n-1){
					union_sets(4*n*i+4*j+2, 4*n*i+4*(j+1)+3);
				}
            }
        }
        int res = 0;
        for(int i = 0; i < 4*n*n; i++){
            if(i == parent[i]) res++;
        }
        return res;
    }
};
