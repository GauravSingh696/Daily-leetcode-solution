class Solution {
public:
    typedef pair<int, int> pr;

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pr, vector<pr>, greater<pr>> pq;

        for(int i=0;i<nums.size();i++) {
            pq.push({nums[i], i});
            
            if(pq.size() > k)
                pq.pop();
        }

        vector<pr> vec;

        while(!pq.empty()) {
            vec.push_back({pq.top().second, pq.top().first});
            pq.pop();
        }

        sort(vec.begin(), vec.end());

        vector<int> result;

        for(auto &it : vec)
            result.push_back(it.second);

        return result;
    }
};
