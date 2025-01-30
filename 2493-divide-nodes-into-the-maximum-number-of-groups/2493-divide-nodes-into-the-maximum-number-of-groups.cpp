class Solution {
public:
    vector<vector<int>> connectedComponent;

    bool bipartite(vector<vector<int>>& adj, int node,vector<int> &visited) {
        vector<int> v;
        v.push_back(node);
        int n = adj.size();
        vector<int> color(n, 0);
        queue<int> q;
        q.push(node);
        color[node] = 1;
        visited[node]=1;

        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            for (auto neighbor : adj[top]) {
                if (color[neighbor] == color[top])
                    return false;
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    v.push_back(neighbor);
                    visited[neighbor]=1;
                    color[neighbor] = (color[top] == 1) ? 2 : 1;
                }
            }
        }
        connectedComponent.push_back(v);
        return true;
    }
    int bfs(vector<vector<int>>& adj, int node) {
        queue<int> q;
        q.push(node);
        vector<int> visited(adj.size(),0);
        visited[node] = 1;

        vector<int> dist(adj.size());

        dist[node] = 1;

        int maxDistance = 1;

        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            for (auto neighbor : adj[top]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                    dist[neighbor] = dist[top] + 1;
                    maxDistance = max(maxDistance, dist[neighbor]);
                }
            }
        }
        return maxDistance;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> visited(n, 0);
        int ans = 0;
        int maxdistance = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (!bipartite(adj, i,visited))
                    return -1;
                else {
                    auto v = connectedComponent[connectedComponent.size() - 1];
                    maxdistance=0;
                    for (auto node : v) {
                        maxdistance = max(maxdistance, bfs(adj, node));
                    }
                    ans += maxdistance;
                }
            }
        }

        return ans;
    }
};