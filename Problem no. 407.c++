class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<pp, vector<pp>, greater<>> boundary_cells;

        vector<vector<bool>> visited(m, vector<bool>(n,false));

        for(int r=0 ; r<m ; r++) {
            for(auto c : {0, n-1}) {
                boundary_cells.push({heightMap[r][c] , {r,c}});
                visited[r][c] = true;
            }
        }

        for(int c=0 ; c<n ; c++) {
            for(auto r : {0, m-1}) {
                boundary_cells.push({heightMap[r][c] , {r,c}});
                visited[r][c] = true;
            }
        }

        int result = 0;

        while(!boundary_cells.empty()) {
            auto [height, cell] = boundary_cells.top();
            boundary_cells.pop();

            int i = cell.first;
            int j = cell.second;

            for(auto &dir : directions) {
                int i_ = i+dir[0];
                int j_ = j+dir[1];

                if(i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_]) {
                    result += max(0 , height - heightMap[i_][j_]);

                    boundary_cells.push({max(height, heightMap[i_][j_]), {i_, j_}});

                    visited[i_][j_] = true;
                }
            }
        }

        return result;
    }
};
