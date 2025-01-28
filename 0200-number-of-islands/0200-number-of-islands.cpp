class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));

        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};    

        int ans=0,flag=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    flag=1;
                    stack<pair<int,int>> s;
                    s.push({i,j});
                    visited[i][j]=true;

                    while(!s.empty()){
                        auto top=s.top();
                        s.pop();

                        for(auto [x,y]:directions){
                            int nx=top.first+x;
                            int ny=top.second+y;
                            if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && grid[nx][ny]=='1'){

                                s.push({nx,ny});
                                visited[nx][ny]=true;
                            }
                        }
                    }
                }
                if(flag){
                    ans++;
                    flag=0;
                }
            }
        }
        return ans;
    }
};