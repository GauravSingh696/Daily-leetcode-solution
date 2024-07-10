class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int>temp=nums,ans;
        int sum=0;
        sort(temp.begin(),temp.end(),greater<int>());
        for(auto it:nums)
        {
            sum+=it;
        }
        int csum=0;
        for(auto it:temp)
        {
            if(sum<csum)
                break;
            
            ans.push_back(it);
            csum+=it;
            sum-=it;
        }
        return ans;
    }
};
