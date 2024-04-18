class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = duration;

        for(int i=0;i<timeSeries.size()-1;i++)
        {
            total += min(timeSeries[i+1]-timeSeries[i], duration);
        }

        return total;
    }
};
