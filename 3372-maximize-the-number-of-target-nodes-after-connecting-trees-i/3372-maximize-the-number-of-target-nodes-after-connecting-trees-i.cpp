class Solution {
public:
    
    int bfs(map<int, set<int>>& adj,int i,int k){
        int n=adj.size();
        vector<int> visited(n,0);
        int count=0;
        queue<int> q;
        q.push(i);
        visited[i]=1;
        int level=0;
        while(!q.empty() && level<=k){
            int s=q.size();
            for(int i=0; i<s; i++){
                int top=q.front();
            q.pop();
            count++;
            
            for(auto neighbour:adj[top]){
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    q.push(neighbour);
                }
            }
            
            }
            level++;
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        map<int ,set<int>> adj1;
        for(auto edge:edges1){
            adj1[edge[0]].insert(edge[1]);
            adj1[edge[1]].insert(edge[0]);
        }
        int n=adj1.size();
        vector<int> dp1(n,0);
        for(int i=0; i<n; i++){
            dp1[i]=bfs(adj1,i,k);
        }
         map<int ,set<int>> adj2;
        for(auto edge:edges2){
            adj2[edge[0]].insert(edge[1]);
            adj2[edge[1]].insert(edge[0]);
        }
        int m=adj2.size();
        int maxVal=0;
        for(int i=0; i<m; i++){
            
            maxVal=max(maxVal,bfs(adj2,i,k-1));
        }
        
        for(int i=0; i<n; i++){
            dp1[i]+=maxVal;
        }
        
        return dp1;
    }
};