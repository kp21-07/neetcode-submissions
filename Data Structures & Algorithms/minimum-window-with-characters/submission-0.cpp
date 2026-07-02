class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        int l = 0;

        unordered_map<char, int> t_map;
        for (char c : t) t_map[c]++;

        unordered_map<char, int> s_map;
        int have = 0, need = t_map.size();

        int res_len = INT_MAX;
        pair<int, int> res = {-1, -1};

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            s_map[c]++;

            if (t_map.count(c) && t_map[c] == s_map[c]) have++;

            while (have == need) {
                if (r-l+1 < res_len) {
                    res_len = r-l+1;
                    res = {l, r};
                }

                s_map[s[l]]--;
                
                if (t_map.count(s[l]) && s_map[s[l]] < t_map[s[l]]) have--;
                l++;
            }
        }

        return res_len == INT_MAX ? "" : s.substr(res.first, res_len);
    }
};
