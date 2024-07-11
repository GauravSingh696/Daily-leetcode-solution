class Solution {
public:
    int minStartValue(vector<int>& nums) {
        for(int i=1 ; i<=2500 ; i++)
        {
            bool flag=true;
            int x=i;
            for(auto it:nums)
            {
                x=x+it;
                if(x<1)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                return i;
        }
        return 0;
    }
};
