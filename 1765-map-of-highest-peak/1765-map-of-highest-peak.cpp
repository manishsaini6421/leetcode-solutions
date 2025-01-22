class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int n=isWater.size();
        int m=isWater[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));

        queue<pair<int,int>> q;

        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]){
                    ans[i][j]=0;
                    q.push({i,j});
                    visited[i][j]=1;
                }
                
                
            }
        }


        vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
               
               for(auto [x,y]:directions){
                int nx=p.first+x;
                int ny=p.second+y;

                if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny]){
                    ans[nx][ny]=ans[p.first][p.second]+1;
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
               }
             
        }
        return ans;
    }
};