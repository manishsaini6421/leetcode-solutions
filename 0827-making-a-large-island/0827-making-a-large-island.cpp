class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ans = 0;
        int id=0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> islandID(n, vector<int>(m, 0));
        unordered_map<int,int> map;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {                
                int area = 0;
                if (!visited[i][j] && grid[i][j]) {
                    id++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;
                    islandID[i][j]=id;
                    area++;
                    while (!q.empty()) {
                        auto top = q.front();
                        q.pop();

                        for (auto [x, y] : directions) {
                            int nx = top.first + x;
                            int ny = top.second + y;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                                !visited[nx][ny] && grid[nx][ny]) {

                                q.push({nx, ny});
                                visited[nx][ny] = 1;
                                islandID[nx][ny]=id;
                                area++;
                            }
                        }
                    }
                    map[id]=area;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int area=0;
                set<int> s;
                if(grid[i][j]==0){
                    for(auto [x,y]:directions){
                        int nx=i+x;
                        int ny=j+y;
                        if(nx>=0 && nx<n && ny>=0 && ny<m && s.find(islandID[nx][ny])==s.end()){
                            
                            area+=map[islandID[nx][ny]];
                            s.insert(islandID[nx][ny]);
                        }
                            
                    }
                    area+=1;
                }
                ans=max(ans,area);
            }
        }
        return ans==0?n*n:ans;
    }
};