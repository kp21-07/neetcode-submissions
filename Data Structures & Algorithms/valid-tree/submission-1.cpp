class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        
        vector<vector<int>> adj(n);
        for (auto& ed : edges) {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        queue<int> q;
        vector<int> p(n, -1);
        q.push(0);
        p[0] = 0;
        int cnt = 0;

        while(!q.empty()) {
            int u = q.front(); q.pop();
            cnt++;
            for (int v : adj[u]) {
                if (p[v] == -1) {
                    p[v] = u;
                    q.push(v);
                }
                else {
                    if (p[u] == v) continue;
                    else return false;
                }
            }
        }

        return cnt == n;
    }
};
