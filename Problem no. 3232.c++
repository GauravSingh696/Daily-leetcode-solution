class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int less = 0;
        int greater = 0;

        for(auto it : nums)
        {
            if(it < 10)
                less += it;
            
            else
                greater += it;
        }

        return !(less == greater);
    }
};
