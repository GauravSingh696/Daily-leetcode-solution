class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int sum = 0;

        for(auto &it : nums) {
            int temp = it;
            while(temp) {
                sum += temp%10;
                temp /= 10;
            }

            mp[sum].push_back(it);
            sum = 0;
        }

        int result = 0;

        for(auto it : mp) {
            sort(it.second.rbegin(), it.second.rend());

            if(it.second.size() > 1)
                result = max(result , it.second[0]+it.second[1]);
        }

        return result==0 ? -1 : result;
    }
};
