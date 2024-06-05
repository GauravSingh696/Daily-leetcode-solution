class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int suma=0,sumb=0;
        for(auto it:aliceSizes)
        {
            suma+=it;
        }
        unordered_map<int,int> mp;
        for(auto it:bobSizes)
        {
            sumb+=it;
            mp[it]++;
        }

        int diff=(suma-sumb)/2;
        for(auto it:aliceSizes)
        {
            if(mp[it-diff]>0)
            {
                return {it,it-diff};
            }
        }
        return {0,0};
    }
};
