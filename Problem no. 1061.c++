class Solution {
public:
    char dfs(unordered_map<char, vector<char>> &adj, char curr_ch, vector<int> &visited) {
        visited[curr_ch - 'a'] = true;
    
        char min_ch = curr_ch;

        for(auto &ch : adj[curr_ch]) {
            if(!visited[ch-'a']) {
                min_ch = min(min_ch , dfs(adj, ch, visited));
            }
        }

        return min_ch;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> adj;

        for(int i=0;i<s1.size();i++) {
            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result;

        for(auto &ch : baseStr) {
            vector<int> visited(26, false);

            char min_ch = min(ch , dfs(adj, ch, visited));

            result.push_back(min_ch);
        }

        return result;
    }
};
