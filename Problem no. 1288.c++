class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        unordered_set<string> st;
        
        for(auto &it : intervals) {
            string str = to_string(it[0]) + "-" + to_string(it[1]);
            st.insert(str);
        }

        for(auto &it : intervals) {
            for(auto &t : intervals) {
                if(t[0] == it[0] && t[1] == it[1])
                    continue;
                
                else {
                    if(t[0] <= it[0] && it[1] <= t[1]) {
                        string str = to_string(it[0]) + "-" + to_string(it[1]);

                        st.erase(str);
                    }
                }
            }
        }

        return st.size();
    }
};
