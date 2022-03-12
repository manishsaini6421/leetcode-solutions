class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
     
       unordered_map<int,vector<int>> m;
      for(auto x:edges){
          int a=x[0];
          int b=x[1];
          m[a].push_back(b);
          m[b].push_back(a);
      }
        vector<bool> visited(n+1,false);
        
        queue<int> q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int x=q.front();
            vector<int> temp=m[x];
            q.pop();
            for(auto y:temp){
                if(visited[y]==false){
                    if(y==destination)
                    return true;
                q.push(y);
                visited[y]=true;
                }
                
                
            }
        }
        return visited[destination];
    }
};