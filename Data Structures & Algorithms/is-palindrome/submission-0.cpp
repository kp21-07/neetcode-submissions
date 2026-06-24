class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i <= j) {
            char l = s[i], r = s[j];
            if (!isalnum(l)) {
                i++;
                continue;
            }
            if (!isalnum(r)) {
                j--;
                continue;
            }
            l = tolower(l);
            r = tolower(r);
            if (l != r) return false;
            i++;
            j--;
        }
        return true;
    }
};
