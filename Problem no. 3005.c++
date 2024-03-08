//  08-03-2024

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        int freq[101];
        int maxfreq=0;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
            maxfreq=max(maxfreq,freq[nums[i]]);
        }

        int sum=0;
        for(int i=0;i<101;i++)
        {
            if(maxfreq==freq[i])
            {
                sum += maxfreq;
            }
        }
        return sum;
    }
};
