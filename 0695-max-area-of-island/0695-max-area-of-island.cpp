class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>> visited(m,vector<bool> (n,false));

        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};

        int ans=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] && !visited[i][j]){
                    stack<pair<int,int>> s;
                    s.push({i,j});
                    visited[i][j]=true;

                    int area=0;
                    while(!s.empty()){
                        auto top=s.top();
                        s.pop();

                        area++;
                        for(auto [x,y]:directions){
                            int nx=top.first+x;
                            int ny=top.second+y;

                            if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && grid[nx][ny]){
                                s.push({nx,ny});
                                visited[nx][ny]=true;
                            }
                        }
                    }
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};