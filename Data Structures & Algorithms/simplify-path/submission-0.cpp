class Solution {
public:
    string simplifyPath(string path) {
        vector<string> path_stk;
        string curr;

        for (char c : path+"/") {
            if (c == '/') {
                if (curr == "..") {
                    if (!path_stk.empty()) path_stk.pop_back();
                }
                else if (!curr.empty() and curr != ".") {
                    path_stk.push_back(curr);
                }
                curr.clear();
            }
            else curr += c;
        }

        string res = "/";

        for (int i = 0; i < path_stk.size(); i++) {
            if (i > 0) res += "/";
            res += path_stk[i];
        }

        return res;
    }
};