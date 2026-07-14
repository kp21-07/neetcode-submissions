class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return {1};

        if (digits.back() < 9) {
            digits.back()++;
            return digits;
        }
        else {
            digits.pop_back();
            vector<int> res = plusOne(digits);
            res.push_back(0);
            return res;
        }
    }
};
