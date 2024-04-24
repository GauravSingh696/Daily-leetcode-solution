// 24-04-2024

class Solution {
public:
    int arr[38];
    int solve(int n) {
        if(n==0)
            return 0;

        else if(n==1 || n==2)
            return 1;
        
        if(arr[n] != -1)
            return arr[n];

        return arr[n] = solve(n-1) + solve(n-2) + solve(n-3);
    }

    int tribonacci(int n)
    {
        memset(arr, -1, sizeof(arr));
        return solve(n);
    }
};
