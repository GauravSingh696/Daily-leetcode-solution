// 29-04-2024

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        string st1 = bitset<32> (k).to_string();
        int temp;

        for(int i=0;i<nums.size();i++)
        {
            temp ^= nums[i];
        }

        string st2 = bitset<32> (temp).to_string();
        int result=0;

        for(int i=0;i<32;i++)
        {
            if(st1[i]!=st2[i])
                result++;
        }

        return result;
    }
};
