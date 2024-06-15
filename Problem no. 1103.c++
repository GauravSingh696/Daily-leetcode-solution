class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> result(n,0);
        int temp = 1;
        int i=0;

        while(candies)
        {
            if(i==n)
                i = 0;

            if(temp > candies)
            {
                result[i] += candies;
                break;
            }

            result[i++] += temp;

            candies -= temp;

            temp++;
        }

        return result;
    }
};
