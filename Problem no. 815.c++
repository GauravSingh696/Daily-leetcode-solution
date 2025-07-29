class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) {
            return 0;
        }

        unordered_map<int, vector<int>> root_to_stop;
        int n = routes.size();

        for(int i=0;i<n;i++) {
            for(int it : routes[i]) {
                root_to_stop[it].push_back(i);
            }
        }

        queue<int> que;
        unordered_set<int> visited;
        int busTaken = 1;

        for(auto it : root_to_stop[source]) {
            que.push(it);
            visited.insert(it);
        }

        while(!que.empty()) {
            int size = que.size();

            while(size--) {
                int idx = que.front();
                que.pop();

                for(int stop : routes[idx]) {
                    if(stop == target)
                        return busTaken;

                    for(auto it : root_to_stop[stop]) {
                        if(!visited.count(it)) {
                            que.push(it);
                            visited.insert(it);
                        }
                    }
                }
            }

            busTaken++;
        }

        return -1;
    }
};
