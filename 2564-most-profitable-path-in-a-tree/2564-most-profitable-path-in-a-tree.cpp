class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<int>& p, vector<int>& amt, vector<bool>& vis, int u, int t) {
        int sum = 0;
        vis[u] = 1;
        if (p[u] == -1 || p[u] > t) sum += amt[u];
        else if (p[u] == t) sum += (amt[u] / 2);
        
        int res = INT_MIN;
        for (int v : adj[u]) {
            if (!vis[v]) res = max(res, dfs(adj, p, amt, vis, v, t + 1));
        }
        
        if (res != INT_MIN) sum += res;
        return sum;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<int> bp;
        vector<vector<int>> adj(n);
        
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        vector<bool> vis(n, 0);
        vector<int> par(n, -1);
        q.push(0);
        vis[0] = 1;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (vis[v]) continue;
                vis[v] = 1;
                par[v] = u;
                q.push(v);
                if (v == bob) {
                    int temp = v;
                    while (temp != -1) {
                        bp.push_back(temp);
                        temp = par[temp];
                    }
                    break;
                }
            }
            if (bp.size()) break;
        }
        
        vector<int> p(n, -1);
        for (int i = 0; i < bp.size(); i++) p[bp[i]] = i;
        fill(vis.begin(), vis.end(), 0);
        return dfs(adj, p, amount, vis, 0, 0);
    }
};