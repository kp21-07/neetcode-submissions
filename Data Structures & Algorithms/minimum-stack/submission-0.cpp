class MinStack {
    stack<int> data;
    stack<int> mini;

public:
    MinStack() {}
    
    void push(int val) {
        data.push(val);
        mini.push(min(val, mini.empty() ? val : mini.top()));
    }
    
    void pop() {
        data.pop();
        mini.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mini.top();
    }
};
