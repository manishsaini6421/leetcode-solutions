class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int n=isWater.size();
        int m=isWater[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]){
                    ans[i][j]=0;
                    pq.push({ans[i][j],i,j});
                    visited[i][j]=1;
                }
                
                
            }
        }

        while(!pq.empty()){
            vector<int> v=pq.top();
            pq.pop();
               
                if(v[1]<n-1 && !visited[v[1]+1][v[2]]){
                    visited[v[1]+1][v[2]]=1;
                    ans[v[1]+1][v[2]]=v[0]+1;
                    pq.push({v[0]+1,v[1]+1,v[2]});
                }
                if(v[1]>0 && !visited[v[1]-1][v[2]]){
                    visited[v[1]-1][v[2]]=1;
                    ans[v[1]-1][v[2]]=v[0]+1;
                    pq.push({v[0]+1,v[1]-1,v[2]});
                }
                if(v[2]<m-1 && !visited[v[1]][v[2]+1]){
                    visited[v[1]][v[2]+1]=1;
                    ans[v[1]][v[2]+1]=v[0]+1;
                    pq.push({v[0]+1,v[1],v[2]+1});
                }
                if(v[2]>0 && !visited[v[1]][v[2]-1]){
                    visited[v[1]][v[2]-1]=1;
                    ans[v[1]][v[2]-1]=v[0]+1;
                    pq.push({v[0]+1,v[1],v[2]-1});
                }
        }
        return ans;
    }
};