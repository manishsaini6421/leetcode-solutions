class Solution {
public:
    
    void bfs(map<int, set<int>>& adj,vector<int> &dp,int i,int k){
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
        dp[i]=count;
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
            bfs(adj1,dp1,i,k);
        }
         map<int ,set<int>> adj2;
        for(auto edge:edges2){
            adj2[edge[0]].insert(edge[1]);
            adj2[edge[1]].insert(edge[0]);
        }
        int m=adj2.size();
        vector<int> dp2(m,0);
        int maxVal=0;
        for(int i=0; i<m; i++){
            bfs(adj2,dp2,i,k-1);
            maxVal=max(maxVal,dp2[i]);
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            dp1[i]+=maxVal;
            cout<<dp1[i]<<" ";
        }
        
        return dp1;
    }
};