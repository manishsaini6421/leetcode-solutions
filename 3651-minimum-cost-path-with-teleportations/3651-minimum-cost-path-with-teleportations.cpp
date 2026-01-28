class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue< 
            tuple<int, int, int, int>,
            vector<tuple<int, int, int, int>>, 
            greater<>> pq;

        vector<vector<vector<int>>> dist(
            m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));

        vector<pair<int,pair<int,int>>> cells;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cells.push_back({grid[i][j],{i,j}});
            }
        }    
        sort(cells.begin(),cells.end());

        vector<int> ptr(k+1,0);

        dist[0][0][0]=0;
        pq.push({0,0,0,0});
        while(!pq.empty()){
            auto [cost,x,y,t]=pq.top();
            pq.pop();
           
            if(cost>dist[x][y][t])continue;

            if(x==m-1 && y==n-1)return dist[x][y][t];
            if(x+1<m){
                int nc=cost+grid[x+1][y];
                if(nc<dist[x+1][y][t]){
                    dist[x+1][y][t]=nc;
                    pq.push({nc,x+1,y,t});
                }
            }

            if(y+1<n){
                int nc=cost+grid[x][y+1];
                if(nc<dist[x][y+1][t]){
                    dist[x][y+1][t]=nc;
                    pq.push({nc,x,y+1,t});
                }
            }

            if(t<k){
                while(ptr[t]<cells.size() && cells[ptr[t]].first<=grid[x][y]){
                    int i=cells[ptr[t]].second.first;
                    int j=cells[ptr[t]].second.second;
                    if(i==x && j==y){
                        ptr[t]++;
                        continue;
                    }
                    if(cost<dist[i][j][t+1]){
                        dist[i][j][t+1]=cost;
                        pq.push({cost,i,j,t+1});
                    }
                    ptr[t]++;
                }
            }

        }
        return -1;
    }
};