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


        vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        while(!pq.empty()){
            vector<int> v=pq.top();
            pq.pop();
               
               for(auto [x,y]:directions){
                int nx=v[1]+x;
                int ny=v[2]+y;

                if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny]){
                    ans[nx][ny]=v[0]+1;
                    visited[nx][ny]=1;
                    pq.push({v[0]+1,nx,ny});
                }
               }
             
        }
        return ans;
    }
};