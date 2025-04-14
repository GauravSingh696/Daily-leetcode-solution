class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int result = 0;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    int a_ = abs(arr[i]-arr[j]);
                    int b_ = abs(arr[j]-arr[k]);
                    int c_ = abs(arr[i]-arr[k]);

                    if(a_ <= a && b_ <= b && c_ <= c) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};
