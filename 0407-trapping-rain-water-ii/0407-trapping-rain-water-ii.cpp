class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
       

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> visited(m,vector<int> (n,0));

        for(int i=0; i<m; i++){
            vector<int> v1(3,0);
            v1[0]=heightMap[i][0];
            v1[1]=i;
            v1[2]=0;
            visited[i][0]=1;
            pq.push(v1);
            vector<int> v2(3,0);
            v2[0]=heightMap[i][n-1];
            v2[1]=i;
            v2[2]=n-1;
            visited[i][n-1]=1;
            pq.push(v2);

        }

        for(int j=0; j<n; j++){
            vector<int> v1(3,0);
            v1[0]=heightMap[0][j];
            v1[1]=0;
            v1[2]=j;
            visited[0][j]=1;
            pq.push(v1);
            vector<int> v2(3,0);
            v2[0]=heightMap[m-1][j];
            v2[1]=m-1;
            v2[2]=j;
            visited[m-1][j]=1;
            pq.push(v2);
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