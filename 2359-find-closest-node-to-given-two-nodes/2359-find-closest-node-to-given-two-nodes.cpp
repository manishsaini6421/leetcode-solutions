#include <algorithm>
class Solution {
public:
   void BFS(unordered_map<int,unordered_set<int>> &adj,vector<int> &distance,int node){
        int n=adj.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(node);
        visited[node]=true;
        int level=0;

        while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                int top=q.front();
                distance[top]=level;
                q.pop();
                for(int neighbour:adj[top]){
                    if(!visited[neighbour]){
                        visited[neighbour]=true;
                        q.push(neighbour);
                    }
                }
            }
            level++;
        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,unordered_set<int>> adj;

        for(int i=0; i<edges.size(); i++){
            if(edges[i]!=-1)
            adj[i].insert(edges[i]);
        }
        int n=edges.size();
        vector<int> distance1(n,INT_MAX),distance2(n,INT_MAX);

        BFS(adj,distance1,node1);
        BFS(adj,distance2,node2);

        int ans=-1;
        int dist=INT_MAX;

        for(int i=0; i<n; i++){
            if(distance1[i]!=INT_MAX && distance2[i]!=INT_MAX)
            if(dist>max(distance1[i],distance2[i])){
                dist=max(distance1[i],distance2[i]);
                ans=i;
            }
        }
        return ans;
    }
};