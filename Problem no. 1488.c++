class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> lakes;
        set<int> dry;
        int n = rains.size();
        vector<int> result(n, 1);

        for(int i=0;i<n;i++) {
            int lake = rains[i];

            if(lake == 0) {
                dry.insert(i);
            } else {
                result[i] = -1;

                if(lakes.count(lake)) {
                    auto it = dry.lower_bound(lakes[lake] + 1);

                    if(it == dry.end()) {
                        return {};
                    }

                    result[*it] = lake;
                    dry.erase(it);
                }

                lakes[lake] = i;
            }
        }

        return result;
    }
};
