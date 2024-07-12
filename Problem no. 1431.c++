class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& can, int extra_can) {
        int check = *max_element(can.begin(), can.end());

        vector<bool> result;

        for(int i=0;i<can.size();i++)
        {
            if(can[i]+extra_can >= check)
                result.push_back(true);
            
            else
                result.push_back(false);
        }

        return result;
    }
};
