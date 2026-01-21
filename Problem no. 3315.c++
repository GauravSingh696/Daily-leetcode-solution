class Solution {
public:
    int value(string bit) {
        int k = 0;
        int ans = 0;

        for(int i=31;i>=0;i--) {
            if(bit[i] == '1') {
                ans += pow(2, k);
            }
            k++;
        }

        return ans;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;

        for(auto &it : nums) {
            string bit = bitset<32>(it).to_string();
            int i = 31;

            for(;i>=0;i--) {
                if(bit[i] == '0')
                    break;
            }

            bit[i+1] = '0';

            if(it < 3) {
                result.push_back(-1);
            } else {
                result.push_back(value(bit));
            }
        }

        return result;
    }
};
