class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> visited(deadends.begin(), deadends.end());

        if(visited.find("0000") != visited.end())
            return -1;

        queue<string> que;
        que.push("0000");

        int result = 0;

        while(!que.empty()) {
            int n = que.size();
            bool flag = false;

            while(n--) {
                string pass = que.front();
                que.pop();

                if(pass == target) {
                    flag = true;
                    break;
                }

                for(int i=0;i<4;i++) {
                    // rotate up
                    char ch = pass[i];

                    if(pass[i] == '9')
                        pass[i] = '0';
                    
                    else
                        pass[i]++;
                    
                    if(visited.find(pass) == visited.end()) {
                        visited.insert(pass);
                        que.push(pass);
                    }

                    // rotate down
                    pass[i] = ch;

                    if(pass[i] == '0')
                        pass[i] = '9';
                    
                    else
                        pass[i]--;
                    
                    if(visited.find(pass) == visited.end()) {
                        visited.insert(pass);
                        que.push(pass);
                    }

                    pass[i] = ch;
                }
            }

            if(flag)
                return result;

            result++;
        }

        return -1;
    }
};
