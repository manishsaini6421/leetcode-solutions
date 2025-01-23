class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> v(n,0);
        set<int> row;
        int ans=0;
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=0; j<m; j++){
                sum+=grid[i][j];
            }
            if(sum>1){
                v[i]=sum;
                row.insert(i);
                ans+=sum;
            }
        } 
        for(int j=0; j<m; j++){
            int count=0;
            int sum=0;
            for(int i=0; i<n; i++){
                if(grid[i][j]){
                    if(row.find(i)!=row.end())count++;
                    else{
                        sum++;
                        count++;
                    }
                }
                
                
            }
            if(count>1)ans+=sum;
        }
        return ans;
    }
};