class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> que(stones.begin(), stones.end());

        while(!que.empty())
        {
            if(que.size() == 1)
                return que.top();

            int a = que.top();
            que.pop();
            
            int b = que.top();
            que.pop();

            int diff = abs(a-b);

            if(diff != 0)
                que.push(diff);
        }

        return 0;
    }
};
