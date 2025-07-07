class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<>> pq;
        int i = 0, count = 0, day;
        int n = events.size();

        while(!pq.empty() || i<n) {
            if(pq.empty())
                day = events[i][0];
            
            while(i<n && events[i][0]==day) {
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()) {
                pq.pop();
                count++;
            }

            day++;

            while(!pq.empty() && pq.top() < day)
                pq.pop();
        }

        return count;
    }
};
