class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int mod = 1e9+7;

        vector<vector<int>> v;
        vector<int> temp;

        for(int i=0;i<n;i++)
        {
            temp.push_back(1);
            
        }

        v.push_back(temp);
        
        int a = 1;
        
        while(k > 0)
        {
            int sum = 0;
            temp.clear();
            
            for(int i=0;i<n;i++)
            {
                sum += v[a-1][i];
                sum %= mod;
                temp.push_back(sum);
            }
            
            v.push_back(temp);
            a++;
            k--;
        }
        
        int size = v.size();
        
        return v[size-1][n-1];
    }
};
