class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i = 0, j = 0, n = fruits.size();
        int result = INT_MIN;

        for(;j<n;j++) {            
            mp[fruits[j]]++;

            while(mp.size() > 2) {
                mp[fruits[i]]--;

                if(mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);
                
                i++;
            }

            result = max(result, j-i+1);
        }

        return result;
    }
};
