// 09-05-2024

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        sort(happiness.begin(), happiness.end());
        reverse(happiness.begin(), happiness.end());
        long long int result = 0;
        long long int count = 0;

        for(long long int i=0;i<n;i++)
        {
            happiness[i] = happiness[i]-count;
            if(happiness[i]<=0)
                break;

            result += happiness[i];
            count++;
            k--;

            if(k==0)
                break;
        }

        return result;
    }
};
