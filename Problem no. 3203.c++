class Solution {
public:
    int n;

    pair<int, int> BFS(unordered_map<int, vector<int>> &adj , int source) {
        queue<int> que;
        que.push(source);

        unordered_map<int, bool> visited;
        visited[source] = true;

        int distance = 0;
        int further_node = source;

        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                int curr = que.front();
                que.pop();

                further_node = curr;

                for(auto &nbr : adj[curr]) {
                    if(!visited[nbr]) {
                        visited[nbr] = true;
                        que.push(nbr);
                    }
                }
            }

            if(!que.empty())
                distance++;
        }

        return {further_node , distance};
    }

    int find_diameter(unordered_map<int , vector<int>> adj) {
        // find a farthest node from a random node - 0
        auto [further_node , distance] = BFS(adj , 0);

        //step 2 - the farthest node we got above is nothing but one of the dia. of adj

        //step 3 - find the further node from the node we got above, that will be other node of diameter.
        auto [other_end_node , diameter] = BFS(adj , further_node);

        return diameter;
    }

    unordered_map<int, vector<int>> build_adj(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = build_adj(edges1);
        unordered_map<int, vector<int>> adj2 = build_adj(edges2);

        int d1 = find_diameter(adj1);
        int d2 = find_diameter(adj2);

        int combined_dia = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1 , d2 , combined_dia});
        
    }
};
