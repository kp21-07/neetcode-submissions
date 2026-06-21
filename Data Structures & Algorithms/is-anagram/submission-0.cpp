class Solution {
public:
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
};
