class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;

        for(auto it : nums) {
            mp[it]++;

            if(mp[it] > 2)
                mp[it]--;
        }

        nums.clear();

        for(auto it : mp) {
            while(it.second--)
                nums.push_back(it.first);
        }

        return nums.size();
    }
};
