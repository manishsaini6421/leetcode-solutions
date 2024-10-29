class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int ans=0;
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==1){
                    if((j>0 && grid[j-1][i-1]<grid[j][i]) || grid[j][i-1]<grid[j][i] || (j<m-1 && grid[j+1][i-1]<grid[j][i] )){
                        dp[j][i]=1;
                        ans=(dp[j][i]>ans)?dp[j][i]:ans;
                    }
                }
                else{
                    if(grid[j][i-1]<grid[j][i] && dp[j][i-1]!=0)
                    {
                        dp[j][i]=1+dp[j][i-1];
                        ans=(dp[j][i]>ans)?dp[j][i]:ans;
                    } 
                    if(j>0 && grid[j-1][i-1]<grid[j][i] && dp[j-1][i-1]!=0){
                        dp[j][i]=max(1+dp[j-1][i-1],dp[j][i]);
                        ans=(dp[j][i]>ans)?dp[j][i]:ans;
                    }
                    if(j<m-1 && grid[j+1][i-1]<grid[j][i] &&dp[j+1][i-1]!=0){
                        dp[j][i]=max(1+dp[j+1][i-1],dp[j][i]);
                        ans=(dp[j][i]>ans)?dp[j][i]:ans;
                    }
                }    
                
            }
           
        }
       
            return ans;
    }
};