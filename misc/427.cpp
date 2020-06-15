class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return AddNodes(grid, grid.size(), 0, 0);
    }

    Node* AddNodes(vector<vector<int>>& grid, int N, int topleftx, int toplefty){

        if (N == 0){
            return NULL;
        } else if (N == 1){
            return new Node(grid[topleftx][toplefty],true, NULL, NULL, NULL, NULL);
        }

        //Check for uniformity
        bool allsame = true;
        int initial_value = grid[topleftx][toplefty];
        for (int i = topleftx; i < topleftx+N; i++){
            for (int j = toplefty; j < toplefty+N; j++){
                if (grid[i][j] != initial_value){
                    allsame = false;
                    break;
                }
            }
            if (!allsame){
                break;
            }
        }


        if (allsame){
            return new Node(initial_value, true, NULL, NULL, NULL, NULL);
        } else {
            return new Node(false, false,
                           AddNodes(grid,N/2,topleftx,toplefty),
                           AddNodes(grid,N/2,topleftx,toplefty+N/2),
                           AddNodes(grid,N/2,topleftx+N/2,toplefty),
                           AddNodes(grid,N/2,topleftx+N/2,toplefty+N/2));
        }

    }
};
