// 10-03-2024

//  solution of the first approach
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(begin(nums1),end(nums1));
        unordered_set<int> st2;

        for(int &num:nums2)
        {
            if(st1.find(num)!=st1.end(num))
            {
                st2.insert(num);
            }
        }
        vector<int>result(begin(st2),end(st2));
        return result;
    }
};


// solution from the second approach.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        vector<int>result;

        while(i<m && j<n)
        {
            if(nums1[i]==nums2[j])
            {
                result.push_back(nums1[i]);

                while(i<m-1 && nums1[i]==nums1[i+1])
                {
                    i++;
                }

                while(j<n-1 && nums2[j]==nums2[j+1])
                {
                    j++;
                }

                i++;    j++;
            }

            else if(nums1[i]<nums2[j])
            {
                i++;
            }

            else
            {
                j++;
            }
        }
        return result;
    }
};
