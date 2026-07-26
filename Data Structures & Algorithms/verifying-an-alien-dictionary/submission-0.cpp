class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int order_index[26] = {0};
        for (int i = 0; i < order.size(); i++)
            order_index[order[i] - 'a'] = i;

        for (int i = 0; i < words.size()-1; i++) {
            string w1 = words[i], w2 = words[i+1];

            for (int j = 0; j < w1.size(); j++) {
                if (j == w2.size()) return false;
                if (w1[j] != w2[j]) {
                    if (order_index[w1[j]-'a'] > order_index[w2[j]-'a'])
                        return false;
                    break;
                }
            }
        }

        return true;
    }
};