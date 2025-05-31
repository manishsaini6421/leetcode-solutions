class Solution {
public:
    int lastLeaf(unordered_map<int, unordered_set<int>>& adj){
        int n = adj.size();
        vector<bool> visited(n, false);
        queue<int> q;
        int leaf=0;
        if (n > 0) {
            q.push(0);
            visited[0] = true;
            while (!q.empty()) {
                    int top = q.front();
                    q.pop();
                    leaf=top;
                    for (int neighbour : adj[top]) {
                        if (!visited[neighbour]) {
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }
                
            }
        }
        return leaf;
    }
    int BFS(unordered_map<int, unordered_set<int>>& adj,int node,int &maxDist) {
        int n = adj.size();
        vector<bool> visited(n, false);
        queue<int> q;
        int level=0;
        int leaf=0;
        if (n > 0) {
            q.push(node);
            visited[node] = true;
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    int top = q.front();
                    leaf=top;
                    q.pop();
                    for (int neighbour : adj[top]) {
                        if (!visited[neighbour]) {
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }
                }
                level++;
            }
        }
        maxDist=level;
        return leaf;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {

        if (edges1.size() == 0 && edges2.size() == 0)
            return 1;
        unordered_map<int, unordered_set<int>> adj1, adj2;

        for (auto& edge : edges1) {
            adj1[edge[0]].insert(edge[1]);
            adj1[edge[1]].insert(edge[0]);
        }

        for (auto& edge : edges2) {
            adj2[edge[0]].insert(edge[1]);
            adj2[edge[1]].insert(edge[0]);
        }
        
        
        int dist1=0;
        int farthestNode1=BFS(adj1,0,dist1);
        int dist2=0;
        BFS(adj1,farthestNode1,dist2);
        int diameter1=max(0,dist2-1);

        
        int farthestNode2=BFS(adj2,0,dist1);
        BFS(adj2,farthestNode2,dist2);
        int diameter2=max(0,dist2-1);

         

        
        
        int half1 = (diameter1 % 2) ? diameter1 / 2 + 1 : diameter1 / 2;
        int half2 = (diameter2 % 2) ? diameter2 / 2 + 1 : diameter2 / 2;

        
        return max(half1 + half2 + 1,max(diameter1,diameter2));
    }
};