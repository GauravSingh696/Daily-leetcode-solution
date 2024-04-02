class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> arr=nums;

        nums.clear();

        int n=arr.size();

        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0)
                nums.push_back(arr[i]);
        }

        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
                nums.push_back(arr[i]);
        }
    }
};
