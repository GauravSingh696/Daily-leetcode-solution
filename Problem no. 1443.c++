class Solution {
public:
    int solve(int curr, int parent, unordered_map<int, vector<int>>& adj, vector<bool>& hasApple) {
        int time = 0;

        for(int &child : adj[curr]) {
            if(child == parent)
                continue;
                
            int val = solve(child, curr, adj, hasApple);
                
            if(val || hasApple[child]) {
                time += val + 2;
            }
        }

        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;

        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return solve(0, -1, adj, hasApple);
    }
};
