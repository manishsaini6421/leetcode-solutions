class Solution {
public:
    void bfs(vector<vector<int>>& adj,int bob,vector<int> &v){
        queue<int> q;
        q.push(0);
        vector<int> visited(adj.size(),0);
        unordered_map<int,int> parent;
        parent[0]=-1;
        visited[0]=1;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            for(auto neighbour:adj[top]){
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    q.push(neighbour);
                    parent[neighbour]=top;
                }
            }
        }

        auto curr=bob;
        while(parent.find(curr)!=parent.end()){
            v.push_back(curr);
            curr=parent[curr];
        }
        
    }

    int dfs2(vector<vector<int>> &adj, vector<int> &amount,int node, vector<int> &visited){
        
        visited[node]=1;

        int temp=INT_MIN;

        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                temp=max(temp,dfs2(adj,amount,neighbour,visited));
            }
           

        }
        return amount[node]+(temp==INT_MIN?0:temp);
       
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n=edges.size();
        vector<vector<int>> adj(amount.size());
        
        for(int i=0; i<n; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> v;
        bfs(adj,bob,v);
        for(auto num:v){
            cout<<num<<" ";
        }
        cout<<endl;
        cout<<v.size()/2<<endl;
        cout<<amount[v.size()/2]<<endl;
        if(v.size()%2)amount[v.size()/2]/=2;
        for(int i=0; i<v.size()/2; i++){
            amount[v[i]]=0;
        }
        for(auto amt:amount){
            cout<<amt<<" ";
        }
        vector<int> visited(amount.size(),0);
       return dfs2(adj,amount,0,visited);
    }
};