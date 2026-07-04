class Solution {
public:
    string decodeString(string s) {
        vector<string> stk;

        for (char& c : s) {
            if (c != ']') stk.push_back(string(1, c));
            else {
                string sub = "";
                while(stk.back()[0] != '[') {
                    sub = stk.back() + sub;
                    stk.pop_back();
                }
                stk.pop_back();
                
                string k_str = "";
                while(!stk.empty() && isdigit(stk.back()[0])) {
                    k_str = stk.back() + k_str;
                    stk.pop_back();
                }
                int k = stoi(k_str);

                string rep = "";
                for (int i = 0; i < k; i++) rep += sub;

                stk.push_back(rep);
            }
        }

        string res = "";
        for (const string& sub : stk) res += sub;

        return res;
    }
};