class Solution {
public:
    bool solve(unordered_map<int, vector<int>>& adj, vector<int>& color, int curr) {
        queue<int> que;
        que.push(curr);
        color[curr] = 1;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int v : adj[u]) {
                if(color[u] == color[v])
                    return false;
                
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    que.push(v);
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(dislikes.empty())
            return true;
        
        unordered_map<int, vector<int>> adj;

        for(auto &it : dislikes) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1, -1);

        for(int i=1;i<=n;i++) {
            if(color[i] == -1) {
                if(!solve(adj, color, i))
                    return false;
            }
        }

        return true;
    }
};
