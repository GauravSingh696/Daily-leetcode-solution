class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        for(int i=0 ; i<tickets.size(); i++) {
            q.push({tickets[i],i});
        }
        int cnt=0;
        while(true) {
            if(q.front().first==1 && q.front().second==k) {
                cnt++;
                break;
            } else if(q.front().first==1) {
                q.pop();
            }
            else {
                q.front().first--;
                q.push(q.front());
                q.pop();
            }
            cnt++;
        }
        return cnt;
    }
};
