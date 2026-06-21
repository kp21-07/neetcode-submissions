class Solution {
private:
    bool isAnagram(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();

        if (len_s != len_t) return false;
        
        unordered_map<char, int> mp_s;
        unordered_map<char, int> mp_t;

        for (int i = 0; i < len_s; i++) {
            mp_s[s[i]]++;
            mp_t[t[i]]++;
        }

        for (const auto& [ch, co] : mp_s) {
            if (mp_t[ch] != co) return false;
        }

        return true;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const auto& s : strs) {
            string s1 = s;
            sort(s1.begin(), s1.end());
            mp[s1].push_back(s);
        }

        vector<vector<string>> res;

        for (const auto& [_, str] : mp) {
            res.push_back(str);
        }
        
        return res;
    }
};
