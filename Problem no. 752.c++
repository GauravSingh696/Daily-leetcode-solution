// 22-04-2024

class Solution {
public:
    void fillNeighbors(queue<string> &que, string &curr, unordered_set<string> &dead)
    {
        for(int i=0;i<4;i++)
        {
            char ch = curr[i];

            char decrease = ch=='0' ? '9' : ch-1;
            char increase = ch=='9' ? '0' : ch+1;

            curr[i] = decrease;

            if(!dead.count(curr))
            {
                dead.insert(curr);
                que.push(curr);
            }

            curr[i] = increase;

            if(!dead.count(curr))
            {
                dead.insert(curr);
                que.push(curr);
            }

            curr[i] = ch;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(begin(deadends), end(deadends));

        string start = "0000";

        if(dead.count(start))
            return -1;

        queue<string> que;
        que.push(start);

        int level = 0;
        while(!que.empty())
        {
            int n = que.size();

            while(n--)
            {
                string curr = que.front();
                que.pop();
                if(curr==target)
                    return level;
                
                fillNeighbors(que, curr, dead);
            }

            level++;
        }

        return -1;
    }
};
