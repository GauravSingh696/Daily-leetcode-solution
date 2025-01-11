class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();

        if(n == k)
            return true;
        
        if(k > n)
            return false;

        unordered_map<char , int> mp;

        for(auto it : s) {
            mp[it]++;
        }

        int odd_count = 0;

        for(auto it : mp) {
            if(it.second%2 != 0) 
                odd_count++;
        }

        if(odd_count <= k)
            return true;
        
        return false;
    }
};
