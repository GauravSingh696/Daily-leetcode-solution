class Solution {
public:
    bool DFS(unordered_map<int,vector<int>> &mp, int src, int dest, vector<bool> &visited) {
        visited[src] = true;

        if(src == dest)
            return true;

        bool reachable = false;

        for(auto &it : mp[src]) {
            if(!visited[it]) {
                reachable = reachable || DFS(mp, it, dest, visited);
            }
        }

        return reachable;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& q) {
        unordered_map<int, vector<int>> mp;

        for(auto it : pre) {
            int u = it[0];
            int v = it[1];

            mp[u].push_back(v);
        }

        vector<bool> result;

        for(auto it : q) {
            int src  = it[0];
            int dest = it[1];

            vector<bool> visited(numCourses, false);
            result.push_back(DFS(mp , src , dest , visited));
        }

        return result;
    }
};
