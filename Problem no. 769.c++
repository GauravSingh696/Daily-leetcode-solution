class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> pre(arr) , post(arr);
        int n = arr.size();

        for(int i=1 ; i<n ; i++) {
            pre[i] = *max_element(arr.begin() , arr.begin() + i);
        }
        
        for(int i=n-2 ; i>=0 ; i--) {
            post[i] = *min_element(arr.begin() + i, arr.end());
        }

        int result = 1;

        for(int i=1 ; i<n ; i++) {
            if(pre[i] < post[i])
                result++;
        }

        return result;
    }
};
