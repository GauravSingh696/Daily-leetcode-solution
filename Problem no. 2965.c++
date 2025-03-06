class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int, int> mp;

        for(auto it : grid) {
            for(auto j : it)
                mp[j]++;
        }

        int missing_number = 1;
        vector<int> result(2);
        bool flag1 = false , flag2 = false;

        for(auto it : mp) {
            if(it.first != missing_number) {
                result[1] = missing_number;
                flag1 = true;
            }
            else
                missing_number++;
            
            if(it.second > 1) {           
                result[0] = it.first;
                flag2 = true;
            }

            if(flag1 && flag2)
                return result;
        }

        result[1] = missing_number;

        return result;
    }
};
