// Breadth-First Search

class Position {
   public :
    int x, y,h,v;
    Position(int xc, int yc,int a) {
        x = xc, y = yc;
        h = a, v = 1-a;
    }
    bool answer(int n) {
        return x == n-1 && y == n-1 && h == 1;
    }
};
class Solution {
    int n;
    string print(int x, int y, int h, int v) {
        return to_string(x) +"-"+to_string(y)+":"+to_string(h)+"-"+to_string(v);
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        Position p(0,1,1); // x, y, horizontal
        queue<Position> q;
        q.push(p);
        int l = 0;
        n = grid.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int>> (n, vector<int> (2,0)));
        while(!q.empty()) {
            int size = q.size();
            for(int z = 0; z < size; z++) {
                Position t = q.front(); q.pop();
                if(t.answer(n)) return l;
                int xh = t.x, yh = t.y;
                //cout << print(t.x,t.y,t.h,t.v) << " ";
                if(dp[xh][yh][t.h] == 1) continue;
                else dp[xh][yh][t.h] = 1;
                if(t.h == 1) { // horizontal
                    int xt = xh, yt = yh-1;
                    if(xh + 1 < n) { // down and clockwise
                        if(grid[xh+1][yh] != 1 && grid[xt+1][yt] != 1) {
                            q.push(Position(xh+1,yh,1)); // down
                            q.push(Position(xh+1,yh-1,0)); // clockwise
                        }
                    }
                    if(yh + 1 < n) { // right
                        if(grid[xh][yh+1] != 1)
                            q.push(Position(xh,yh+1,1));
                    }
                }
                if(t.v == 1){
                    int xt = xh-1, yt = yh;
                    if(xh + 1 < n)  // down
                        if(grid[xh+1][yh] != 1)
                            q.push(Position(xh+1, yh, 0));

                    if(yh + 1 < n) { // right and counter clockwise
                        if(grid[xh][yh+1] != 1 && grid[xt][yt+1] != 1) {
                            q.push(Position(xh-1,yh+1,1));
                            q.push(Position(xh,yh+1,0));
                        }
                    }
                }
            }
            l++;
        }
        return -1;
    }
};
