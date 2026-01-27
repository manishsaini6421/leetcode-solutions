class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, set<pair<int, int>>> adjList;
        for (auto edge : edges) {
            adjList[edge[0]].insert({edge[1], edge[2]});
            adjList[edge[1]].insert({edge[0], 2 * edge[2]});
        }
        vector<int> visited(n, 0);
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        set<pair<int, int>> s;
        // Distance, Nodename
        s.insert({0, 0});
        while (!s.empty()) {
            auto top = *s.begin();
            int pathLength = top.first;
            int node = top.second;
            visited[node] = 1;
            s.erase(s.begin());
            for (auto pair : adjList[node]) {
                int neighbour = pair.first;
                int edgeWeight = pair.second;
                if (!visited[neighbour]) {
                    if (dist[neighbour] > edgeWeight + pathLength) {
                        dist[neighbour] = edgeWeight + pathLength;
                        s.insert({dist[neighbour], neighbour});
                    }
                    
                }
            }
        }
        return (dist[n - 1] != INT_MAX) ? dist[n - 1] : -1;
    }
};