#include <algorithm>
class Solution {
public:
   void BFS(vector<int>& edges,vector<int> &distance,int node){
        vector<bool> visited(distance.size(),false);
        queue<int> q;
        q.push(node);
        visited[node]=true;
        int level=0;

        while(!q.empty()){
            
                int top=q.front();
                distance[top]=level;
                q.pop();
                if(edges[top]!=-1){
                    int neighbour=edges[top];
                    if(!visited[neighbour]){
                        visited[neighbour]=true;
                        q.push(neighbour);
                    }
                }
            
            level++;
        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
       
        int n=edges.size();
        vector<int> distance1(n,INT_MAX),distance2(n,INT_MAX);

        BFS(edges,distance1,node1);
        BFS(edges,distance2,node2);

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