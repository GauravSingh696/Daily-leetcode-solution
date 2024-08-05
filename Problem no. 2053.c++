// 05-08-2024

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int count=0;
        unordered_map<string,int> mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        for(auto it:arr)
        {
            if(mp[it]==1)
                count++;
            
            if(count==k)
            {
                return it;
            }
        }
        return "";
    }
};
