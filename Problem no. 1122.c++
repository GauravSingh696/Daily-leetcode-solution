class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        int n = arr1.size();

        for(int i=0;i<n;i++)
        {
            mp[arr1[i]]++;
        }

        vector<int> result;

        for(int i=0;i<arr2.size();i++)
        {
            while(mp[arr2[i]] != 0)
            {
                result.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }

        vector<int> v;

        for(auto it : mp)
        {
            while(it.second != 0)
            {
                v.push_back(it.first);
                it.second--;
            }
        }

        sort(v.begin() , v.end());

        for(int i=0;i<v.size();i++)
        {
            result.push_back(v[i]);
        }

        return result;
    }
};
