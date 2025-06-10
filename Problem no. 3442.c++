class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;

        for(auto &it : s) {
            mp[it]++;
        }

        vector<int> even, odd;

        for(auto &it : mp) {
            int val = it.second;

            if(val%2 == 0)
                even.push_back(val);
            
            else
                odd.push_back(val);
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        int n1 = even.size();
        int n2 = odd.size();

        return max((- even[0] + odd[n2-1]) , (- even[n1-1] + odd[0]));
    }
};
