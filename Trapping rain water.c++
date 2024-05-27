class Solution{

    // Function to find the trapped water between the blocks.
    public:
    
        long long trappingWater(int arr[], int n){
        // code here
            
            int left_max[n], right_max[n];
            
            left_max[0] = arr[0];
            
            for(int i=1;i<n;i++)
            {
                left_max[i] = max(arr[i] , left_max[i-1]);
            }
            
            right_max[n-1] = arr[n-1];
            
            for(int i=n-2;i>=0;i--)
            {
                right_max[i] = max(arr[i] , right_max[i+1]);
            }
            
            long long int result = 0;
        
            for(int i=1;i<n-1;i++)
            {
                result += min(left_max[i] , right_max[i]) - arr[i];
            }
            
            return result;
        
        }
};
