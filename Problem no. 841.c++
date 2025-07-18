class Solution {
public:
    void solve(int curr, vector<vector<int>>& rooms, vector<int>& visited) {
        visited[curr] = 1;

        for(auto &it : rooms[curr]) {
            if(!visited[it]) {
                solve(it, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);

        solve(0, rooms, visited);

        return count(visited.begin(), visited.end(), 0) ? false : true ;
    }
};
