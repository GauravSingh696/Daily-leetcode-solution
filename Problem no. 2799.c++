class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());

        int unique = st.size();

        int i = 0 , j = 0, result = 0;
        unordered_map<int, int> mp;
        
        while(j<n) {
            mp[nums[j]]++;

            while(mp.size() == unique) {
                result += n - j;
                mp[nums[i]]--;

                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                
                i++;
            }

            j++;
        }

        return result;
    }
};
