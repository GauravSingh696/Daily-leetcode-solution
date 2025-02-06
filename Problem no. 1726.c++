// approach 1...

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuples = 0;

        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i++) {
            for(int j=n-1;j>i;j--) {
                int product = nums[i] * nums[j];
                unordered_set<int> st;

                for(int k=i+1;k<j;k++) {
                    if(product%nums[k] == 0) {
                        int d_val = product / nums[k];

                        if(st.count(d_val))
                            tuples++;
                        
                        st.insert(nums[k]);
                    }
                }
            }
        }

        return (tuples * 8);
    }
};


// approach 2...

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuples = 0;
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                mp[nums[i] * nums[j]]++;
            }
        }

        for(auto it : mp) {
            int freq = it.second;

            tuples += (freq * (freq-1)) / 2;
        }

        return (tuples * 8);
    }
};
