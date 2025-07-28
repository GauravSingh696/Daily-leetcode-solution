class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long result = -1, curr_sum = 0;

        for(int &it : nums) {
            if(curr_sum > it)
                result = curr_sum + it;
            
            curr_sum += it;
        }

        return result;
    }
};
