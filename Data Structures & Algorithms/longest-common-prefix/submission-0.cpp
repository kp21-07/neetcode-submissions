class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];
        int n = strs.size();
        for (int i = 1; i < n; i++) {
            int j = 0;

            while (j < min(strs[i].size(), pre.size())) {
                if (pre[j] != strs[i][j]) break;
                j++;
            }

            pre = pre.substr(0, j);
        }

        return pre;
    }
};