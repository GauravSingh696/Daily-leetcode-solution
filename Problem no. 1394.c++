class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }

        vector<int> res;

        for(auto it : mp)
        {
            if(it.first == it.second)
                res.push_back(it.first);
        }

        if(res.empty())
            return -1;

        return *max_element(res.begin(), res.end());

    }
};
