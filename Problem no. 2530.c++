// 14-10-2024

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long result=0;
        priority_queue<int> pq(nums.begin(),nums.end());

        while(k--){
            int x = pq.top();
            pq.pop();
            result += x;
            x = ceil(x/3.0);
            pq.push(x);
        }

        return result;
    }
};
