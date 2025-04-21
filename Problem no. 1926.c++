class Solution {
public:
    vector<vector<int>> directions{{0,1}, {0,-1}, {1,0}, {-1,0}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> que;
        que.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                pair<int,int> pr = que.front();
                que.pop();

                int i = pr.first;
                int j = pr.second;

                if((pr != make_pair(entrance[0], entrance[1])) && (i==0 || i==m-1 || j==0 || j==n-1))
                    return steps;
                
                for(auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ <n && maze[i_][j_] != '+') {
                        que.push(make_pair(i_, j_));
                        maze[i_][j_] = '+';
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
