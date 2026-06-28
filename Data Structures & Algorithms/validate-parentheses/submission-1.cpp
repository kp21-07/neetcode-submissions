class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') open.push(c);
            else {
                if (open.empty()) return false;
                char popped = open.top();
                open.pop();
                switch(c) {
                    case ')':
                        if (popped != '(') return false;
                        else break;
                    case ']':
                        if (popped != '[') return false;
                        else break;
                    case '}':
                        if (popped != '{') return false;
                        else break;
                }
            }
        }
        return open.empty();
    }
};
