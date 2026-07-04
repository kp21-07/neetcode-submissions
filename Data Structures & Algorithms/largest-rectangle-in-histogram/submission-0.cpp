class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;
        stack<int> bars;

        for (int i = 0; i < n+1; i++) {
            while (!bars.empty() && (i == n || heights[bars.top()] >= heights[i])) {
                int h = heights[bars.top()];
                bars.pop();
                int w = bars.empty() ? i : (i-1)-bars.top();
                max_area = max(max_area, h*w);
            }
            bars.push(i);
        }

        return max_area;
    }
};
