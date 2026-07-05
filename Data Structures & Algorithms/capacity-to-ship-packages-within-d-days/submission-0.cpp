class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for (int w : weights) {
            l = max(l, w);
            r += w;
        }

        int res = r;

        while (l <= r) {
            int mid = (l+r)/2;
            int ships = 1;
            int curr_cap = mid;
            bool can_ship = true;
            for (int w : weights) {
                if (curr_cap - w < 0) {
                    ships++;
                    if (ships > days) {
                        can_ship = false;
                        break;
                    }
                    curr_cap = mid;
                }
                curr_cap -= w;
            }

            if (can_ship) {
                res = min(res, mid);
                r = mid-1;
            }
            else l = mid+1;
        }

        return res;
    }
};