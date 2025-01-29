class Solution {
public:
    bool isCycle(vector<vector<int>> &adj,int node,vector<int> &visited){

        stack<pair<int,int>> s;
        int n=adj.size();
        
        s.push({node,-1});
        visited[node]=1;
        while(!s.empty()){
            auto top=s.top();
            s.pop();
            for(auto vertex:adj[top.first]){

                if(visited[vertex] && vertex!=top.second){
                    cout<<vertex<<" "<<top.second<<endl;
                    return true;
                    }
                else if(!visited[vertex]){
                    s.push({vertex,top.first});
                    visited[vertex]=1;
                }
                
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
      
        vector<vector<int>> adj(n+1);
        vector<int> visited(n+1,0);

        for(int i=0; i<n; i++){
            if(visited[edges[i][1]] && visited[edges[i][0]])return edges[i];
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
            visited[edges[i][1]]=1;
            visited[edges[i][0]]=1;
        }
        
        // for(int i=n-1; i>=0; i--){
        //     if(isCycle(adj,edges[i][0],visited))return edges[i];
        // }
        return edges[0];
    }
};