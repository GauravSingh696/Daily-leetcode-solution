class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> BOB_map;
    int result = INT_MIN;

    bool Bob_DFS(int curr, int time, vector<bool> &visited) {
        BOB_map[curr] = time;
        visited[curr] = true;

        if(curr == 0) {
            return true;
        }

        for(auto &nbr : adj[curr]) {
            if(!visited[nbr]){
                if(Bob_DFS(nbr, time+1, visited))
                    return true;
            }
        }

        BOB_map.erase(curr);
        return false;
    }

    void Alice_DFS(int curr, int time, int income, vector<bool> &visited, vector<int>& amount) {
        visited[curr] = true;

        if(BOB_map.find(curr) == BOB_map.end() || time<BOB_map[curr]) {
            income += amount[curr];
        }
        else if(time == BOB_map[curr]) {
            income += amount[curr]/2;
        }
        
        if(adj[curr].size()==1 && curr!=0) {
            result = max(result, income);
        }

        for(auto &nbr : adj[curr]) {
            if(!visited[nbr]) {
                Alice_DFS(nbr, time+1, income, visited, amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int n = amount.size();
        vector<bool> visited(n, false);
        Bob_DFS(bob, 0, visited);

        visited.assign(n, false);
        int income = 0;
        Alice_DFS(0, 0, income, visited, amount);

        return result;
    }
};
