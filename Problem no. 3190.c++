class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;

        for(auto it : nums)
        {
            if((it+1)%3 == 0)
                result++;
            
            else if((it-1)%3 == 0)
                result++;
        }

        return result;
    }
};
