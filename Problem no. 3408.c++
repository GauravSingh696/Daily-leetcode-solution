class TaskManager {
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> user, task;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &it: tasks) {
            add(it[0], it[1], it[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        user[taskId] = userId;
        task[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        pq.push({newPriority, taskId});
        task[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        task[taskId] = -1;
    }
    
    int execTop() {
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if(it.first == task[it.second]) {
                task[it.second] = -1;
                return user[it.second];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
