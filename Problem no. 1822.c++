class Solution {
public:
    int arraySign(vector<int>& nums) {
        if(count(nums.begin(), nums.end(), 0)) {
            return 0;
        }
        
        int neg = 0;

        for(auto &it : nums) {
            if(it < 0)
                neg++;
        }

        if(neg%2 == 0)
            return 1;
        
        return -1;
    }
};
