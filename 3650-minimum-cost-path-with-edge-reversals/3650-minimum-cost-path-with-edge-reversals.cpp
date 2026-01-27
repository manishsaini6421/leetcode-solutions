class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,set<pair<int,int>>> connections;
        for(auto edge:edges){
            connections[edge[0]].insert({edge[1],edge[2]});
            connections[edge[1]].insert({edge[0],2*edge[2]});
        }
        vector<int> visited(n,0);
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
       set<pair<int,int>> s;
       //Distance, Nodename
       s.insert({0,0});
       while(!s.empty()){
         auto top=*s.begin();
         visited[top.second]=1;
         s.erase(s.begin());
         for(auto node:connections[top.second]){
            if(!visited[node.first]){
                if(dist[node.first]>node.second+top.first){
                    dist[node.first]=node.second+top.first;
                }
                s.insert({dist[node.first],node.first});
            }
            
         }
       }
       return (dist[n-1]!=INT_MAX)?dist[n-1]:-1;
        

    }
};