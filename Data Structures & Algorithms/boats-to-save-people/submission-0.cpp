class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int boats = 0, l = 0, r = people.size()-1;

        while(l <= r) {
            int rem = limit-people[r--];
            boats++;
            if (l <= r && rem >= people[l]) l++;
        }

        return boats;
    }
};