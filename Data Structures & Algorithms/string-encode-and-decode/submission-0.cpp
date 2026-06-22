class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for (const string& str : strs) {
            s.append(to_string(str.size()));
            s.push_back('#');
            s.append(str);
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j-i));
            i = j+1;
            j = i+len;
            v.push_back(s.substr(i, len));
            i = j;
        }
        return v;
    }
};
