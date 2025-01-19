class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
       

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> visited(m,vector<int> (n,0));

        for(int i=0; i<m; i++){
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][n-1],i,n-1});
            visited[i][0]= visited[i][n-1]=1;

        }

        for(int j=0; j<n; j++){
            pq.push({heightMap[0][j],0,j});            
            pq.push({heightMap[m-1][j],m-1,j});
            visited[0][j]=visited[m-1][j]=1;
        }
       
       int ans=0;
       while(!pq.empty()){
            vector<int> v=pq.top();

            pq.pop();
            if(v[2]<n-1 && !visited[v[1]][v[2]+1]){
                ans+=max(0,v[0]-heightMap[v[1]][v[2]+1]);
                visited[v[1]][v[2]+1]=1;
                pq.push(vector<int> {max(v[0],heightMap[v[1]][v[2]+1]),v[1],v[2]+1});
            }
            if(v[2]>0 && !visited[v[1]][v[2]-1]){
                ans+=max(0,v[0]-heightMap[v[1]][v[2]-1]);
                visited[v[1]][v[2]-1]=1;
                pq.push(vector<int> {max(v[0],heightMap[v[1]][v[2]-1]),v[1],v[2]-1});
            }
            if(v[1]<m-1 && !visited[v[1]+1][v[2]]){
                ans+=max(0,v[0]-heightMap[v[1]+1][v[2]]);
                visited[v[1]+1][v[2]]=1;
                pq.push(vector<int> {max(v[0],heightMap[v[1]+1][v[2]]),v[1]+1,v[2]});
            }
            if(v[1]>0 && !visited[v[1]-1][v[2]]){
                ans+=max(0,v[0]-heightMap[v[1]-1][v[2]]);
                visited[v[1]-1][v[2]]=1;
                pq.push(vector<int> {max(v[0],heightMap[v[1]-1][v[2]]),v[1]-1,v[2]});
            }
            
                
       }

        return ans;

    }
};