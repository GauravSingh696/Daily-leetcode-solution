class Solution {
public:
    int distanceBetweenBusStops(vector<int>& dis, int start, int des) {
        int n = dis.size();
        
        if(start > des)
        {
            swap(start , des);
        }

        int sum = 0;
        int a = 0;
        int b = 0;

        for(int i=0;i<n;i++)
        {
            sum += dis[i];
        }

        for(int i=start;i<des;i++)
        {
            b += dis[i];
        }

        a = sum-b;

        return min(a, b);
    }
};
