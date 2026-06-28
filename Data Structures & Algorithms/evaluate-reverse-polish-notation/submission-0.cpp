class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const auto t : tokens) {
            if (t == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if (t == "-") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if (t == "*") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if (t == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }
            else {
                s.push(stoi(t));
            }
        }

        return s.top();    
    }
};
