class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin() , gifts.end());

        while(k) {
            int temp = pq.top();
            pq.pop();
            pq.push(sqrt(temp));
            k--;
        }

        long long result = 0;

        while(!pq.empty()) {
            result += pq.top();
            pq.pop();
        }

        return result;
    }
};
