class Solution {
public:
    bool solve(unordered_map<int, vector<int>> &adj, int src, int tar, vector<bool> &visited) {
        visited[src] = true;

        for(auto &it : adj[src]) {
            if(it == tar)
                return true;

            if(!visited[it]) {
                if(solve(adj, it, tar, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for(auto &it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
        }

        for(auto &it : adj) {
            vector<bool> visited(numCourses, false);

            if(solve(adj, it.first, it.first, visited)) {
                return false;
            }
        }

        return true;
    }
};
