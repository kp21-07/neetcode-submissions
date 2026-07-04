class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.rbegin(), cars.rend());

        int fleets = 1;
        double prev_time = (double) (target - cars[0].first) / (cars[0].second);

        for (int i = 1; i < n; i++) {
            double curr_time = (double) (target - cars[i].first) / (cars[i].second);
            if (curr_time > prev_time) {
                fleets++;
                prev_time = curr_time;
            }
        }

        return fleets;
    }
};
