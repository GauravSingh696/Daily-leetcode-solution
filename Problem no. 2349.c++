class NumberContainers {
public:
    unordered_map<int, int> idx_num;
    unordered_map<int, set<int>> num_idx;

    NumberContainers() {}
    
    void change(int index, int number) {
        if(idx_num.count(index)) {
            int prev = idx_num[index];
            num_idx[prev].erase(index);

            if(num_idx[prev].empty())
                num_idx.erase(prev);
        }
        idx_num[index] = number;
        num_idx[number].insert(index);
    }
    
    int find(int number) {
        if(num_idx.count(number))
            return *num_idx[number].begin();
        
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
