class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int result = 0;
        
        while(pq.top()<k) {
            long long x = pq.top();
            pq.pop();
            
            long long y = pq.top();
            pq.pop();

            long long val = min(x, y) * 2 + max(x, y);

            pq.push(val);
            result++;
        }

        return result;
    }
};
