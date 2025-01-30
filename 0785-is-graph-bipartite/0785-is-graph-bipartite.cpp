class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> visited(n, 0);

        vector<int> color(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i]=1;
                color[i]=1;
                while (!q.empty()) {
                    auto top = q.front();
                    q.pop();

                    for (auto node : graph[top]) {
                        if (color[node] == color[top])
                            return false;
                        if (!visited[node]) {
                            visited[node] = 1;
                            q.push(node);
                            color[node] = (color[top] == 1) ? 2 : 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};