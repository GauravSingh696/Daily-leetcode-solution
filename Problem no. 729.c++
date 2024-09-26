// 26-09-2024

class MyCalendar {
public:
    vector<pair<int, int>> pr;
    MyCalendar() {}
    
     bool book(int start, int end) {
        for (auto& it : pr) {
            int a = it.first;
            int b = it.second;

            if (start < b && end > a) {
                return false;
            }
        }
    
        pr.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
