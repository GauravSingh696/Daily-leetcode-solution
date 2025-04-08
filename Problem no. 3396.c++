class Solution {
public:
    bool check(unordered_map<int,int> &mp) {
        for(auto &it : mp) {
            if(it.second > 1)
                return false;
        }

        return true;
    }

    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto &it : nums) {
            mp[it]++;
        }

        int result = 0 , n = nums.size();

        for(int i=0;i<n;i+=3) {
            if(check(mp))
                return result;
            
            mp[nums[i]]--;

            if(i+1 < n)
                mp[nums[i+1]]--;
            
            if(i+2 < n)
                mp[nums[i+2]]--;

            result++;
        }

        return result;
    }
};
