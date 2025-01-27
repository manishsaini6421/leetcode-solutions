class Solution {
public:
    int ans=-1;
    void cycleLength(int node, vector<int>& edges,vector<bool> &visited,unordered_map<int,int> &dist){
        visited[node]=true;
        int neighbor=edges[node];
        if(neighbor!=-1 && !visited[neighbor]){
            dist[neighbor]=dist[node]+1;
            cycleLength(neighbor,edges,visited,dist);
        }
        else if(neighbor!=-1 && dist[neighbor]){
            ans=max(ans,dist[node]-dist[neighbor]+1);
        }
    }

    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        
        vector<bool> visited(n,0);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                unordered_map<int,int> dist;
                dist[i]=1;
                cycleLength(i,edges,visited,dist);
            }
        }
        return ans;
    }
};