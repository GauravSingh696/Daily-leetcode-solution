class Solution {
public:
    void dfs(int curr, unordered_map<int, unordered_set<int>> &graph, vector<bool> &visited) {
        visited[curr] = true;

        for(auto &it : graph[curr]) {
            if(!visited[it])
                dfs(it, graph, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, unordered_set<int>> graph;
        int n = isConnected.size();

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i!=j && isConnected[i][j]) {
                    graph[i+1].insert(j+1);
                    graph[j+1].insert(i+1);
                }
            }
        }
        
        vector<bool> visited(n+1, false);
        int result = 0;
        
        for(int i=1;i<=n;i++) {
            if(!visited[i]) {
                dfs(i, graph, visited);
                result++;
            }
        }

        return result;
    }
};
