class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();

        if(n<3)
            return false;

        int peeks = 0;

        for(int i=1;i<n-1;i++)
        {
            int prev = arr[i-1];
            int curr = arr[i];
            int next = arr[i+1];

            if(prev==curr || curr==next)
                return false;
            
            if(prev>curr && curr<next)
                return false;
            
            if(prev<curr && curr>next)
            {
                peeks++;

                if(peeks>1)
                    return false;
            }
        }

        return peeks==1;
    }
};
