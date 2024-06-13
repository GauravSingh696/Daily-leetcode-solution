// 13-06-2024

class Solution {
  public:
    int mod = 1e9+7;
    int arr[1000001];
    
    long int find(int n)
    {
        if(n==0 || n==1 || n==2)
            return 1;
        
        if(arr[n] != -1)
            return arr[n];
            
        return arr[n] = (find(n-2) + find(n-3)) % mod;
    }
  
    long int padovanSequence(int n) {
        // code here.
        
        memset(arr, -1, sizeof(arr));
        
        return find(n);
        
    }
};
