class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vec(n, false);

        queue<int> que;
        
        for(auto &it : rooms[0])
            que.push(it);

        vec[0] = true;

        while(!que.empty()) {
            int room = que.front();
            que.pop();

            if(vec[room])
                continue;
            
            vec[room] = true;

            for(auto it : rooms[room]) {
                que.push(it);
            }
        }

        for(auto it : vec) {
            if(it == false)
                return false;
        }

        return true;
    }
};
