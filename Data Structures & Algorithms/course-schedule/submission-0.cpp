class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> in_degree(n, 0);

        for (auto& ed : prerequisites) {
            in_degree[ed[1]]++;
            adj[ed[0]].push_back(ed[1]);
        }

        vector<int> visited(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) q.push(i);
        }

        int finish = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            finish++;
            for (int v : adj[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0) q.push(v);
            }
        }

        return finish == n;
    }
};
