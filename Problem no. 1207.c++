class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> mp;
        int n = arr.size();

        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }

        int size = mp.size();

        int freq[size];
        int idx = 0;

        for(auto it : mp)
        {
            freq[idx++] = it.second;
        }

        sort(freq , freq+size);

        for(int i=0;i<size-1;i++)
        {
            if(freq[i] == freq[i+1])
                return false;
        }

        return true;
    }
};
