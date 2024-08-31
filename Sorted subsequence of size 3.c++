// 31-08-2024

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        
        if(n < 3)
            return {};
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[j] <= arr[i])
                    continue;
                    
                for(int k=j+1;k<n;k++)
                {
                    if(arr[k] <= arr[j])
                        continue;
                    
                    return {arr[i] , arr[j] , arr[k]};
                }
            }
        }
        
        return {};
    }
};
