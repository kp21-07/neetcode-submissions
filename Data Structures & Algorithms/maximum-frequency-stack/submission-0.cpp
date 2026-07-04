class FreqStack {
    unordered_map<int, int> count;
    unordered_map<int, stack<int>> stacks;
    int max_count;

public:
    FreqStack() {
        max_count = 0;    
    }
    
    void push(int val) {
        int val_count = ++count[val];
        if (val_count > max_count) {
            max_count = val_count;
            stacks[val_count] = stack<int>();
        }
        stacks[val_count].push(val);
    }
    
    int pop() {
        int res = stacks[max_count].top();
        stacks[max_count].pop();
        count[res]--;
        if (stacks[max_count].empty()) max_count--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */