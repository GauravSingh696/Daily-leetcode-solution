//  14-03-2024

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int count=0;
        int preFixSum=0;
        unordered_map<int, int> preFixSumCount;

        for(int num:nums)
        {
            preFixSum += num;
            
            if(preFixSum == goal)
                count++;

            count += preFixSumCount[preFixSum - goal];
            preFixSumCount[preFixSum]++;
        }

        return count;
    }
};
