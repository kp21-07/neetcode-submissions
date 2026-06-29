class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> fwd;
        vector<int> res;
        for (int i : asteroids) {
            if (i > 0) fwd.push(i);
            else {
                bool exploded = false;
                
                while(!fwd.empty()) {
                    if (fwd.top() < abs(i)) {
                        fwd.pop();
                    } else if (fwd.top() == abs(i)) {
                        fwd.pop();
                        exploded = true;
                        break;
                    } else {
                        exploded = true;
                        break;
                    }
                }
                
                if (!exploded) {
                    res.push_back(i);
                }
            }
        }

        vector<int> rem;
        while (!fwd.empty()) {
            rem.push_back(fwd.top());
            fwd.pop();
        }

        reverse(rem.begin(), rem.end());
        res.insert(res.end(), rem.begin(), rem.end());

        return res;
    }
};