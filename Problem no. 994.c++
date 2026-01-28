class Solution {
  public:
    int m, n;
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

    void solve(queue<pair<int, int>> &que, vector<vector<int>> &grid, int &fresh_orange) {
        while(!que.empty()) {
            auto pr = que.front();
            que.pop();
            int i = pr.first;
            int j = pr.second;

            if(fresh_orange == 0)
                return ;

            for(auto it : dir) {
                int i_ = it[0] + i;
                int j_ = it[1] + j;

                if(i_>=0 && j_>=0 && i_<m && j_<n && grid[i_][j_]==1) {
                    fresh_orange--;
                    grid[i_][j_] = 2;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int result = 0;
        int fresh_orange = 0, rotten = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    fresh_orange++;
                }
                if(grid[i][j] == 2)
                    rotten++;
            }
        }

        if(fresh_orange == 0) return 0;
        if(rotten == 0) return -1;

        queue<pair<int, int>> que;
        set<pair<int, int>> st;

        while(fresh_orange) {
            for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                    if(grid[i][j] == 2 && st.find({i, j}) == st.end()) {
                        st.insert({i, j});
                        que.push({i, j});
                    }
                }
            }

            if(que.empty()) break;
            solve(que, grid, fresh_orange);
            result++;
        }

        return fresh_orange==0 ? result : -1 ;
    }
};
