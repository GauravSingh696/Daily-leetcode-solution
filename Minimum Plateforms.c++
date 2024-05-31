class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	 int ans = 1 ,count = 1,j=0,i=1;
        
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        while(i<n && j<n){
            
            if(dep[j]>=arr[i]){
             
                i++;
                count++;
                
            }
            
            else{ 
               j++;
                count--;
            }
            ans = max(count,ans);
        }
        
        return ans;
    }
};
