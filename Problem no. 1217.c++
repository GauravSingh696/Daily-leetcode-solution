class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int even = 0;
        int odd = 0;

        for(auto it : pos)
        {
            if(it%2 == 0)
                even++;
            
            else
                odd++;
        }

        return min(even , odd);
    }
};
