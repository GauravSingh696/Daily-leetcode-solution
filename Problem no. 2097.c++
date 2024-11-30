class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int , vector<int>> adj;
        unordered_map<int, int> indegree , outdegree;

        for(auto &it : pairs) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        // find the first element of first pair.
        int start_node = pairs[0][0];
        for(auto &it : adj) {
            int node = it.first;

            if(outdegree[node] - indegree[node] == 1) {
                start_node = node;
                break;
            }
        }

        vector<int> vec;
        stack<int> st;
        st.push(start_node);

        while(!st.empty()) {
            int curr = st.top();

            if(!adj[curr].empty()) {
                int neighbour = adj[curr].back();
                adj[curr].pop_back();
                st.push(neighbour);
            }
            else {
                vec.push_back(curr);
                st.pop();
            }
        }

        reverse(vec.begin(), vec.end());
        vector<vector<int>> result;

        for(int i=0;i<vec.size()-1;i++) {
            result.push_back({vec[i] , vec[i+1]});
        }

        return result;
    }
};
