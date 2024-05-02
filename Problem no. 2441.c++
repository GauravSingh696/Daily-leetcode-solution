// 02-04-2024

class Solution {
public:
    int findMaxK(vector<int>& nums) {    
        set<int> st;
        int result = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(st.find(-nums[i]) != st.end())
            {
                result = max(result, abs(nums[i]) );
            }

            st.insert(nums[i]);
        }

        return result==0 ? -1 : result;
    }
};
