class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack;
        int sum = 0;
        for (const auto op : operations) {
            if (op == "+") {
                int top = stack.top(); stack.pop();
                int newTop = top + stack.top();
                stack.push(top);
                stack.push(newTop);
                sum += newTop;
            } else if (op == "D") {
                stack.push(2 * stack.top());
                sum += stack.top();
            } else if (op == "C") {
                sum -= stack.top();
                stack.pop();
            } else {
                stack.push(stoi(op));
                sum += stack.top();
            }
        }
        return sum;
    }
};