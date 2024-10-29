class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j]=(grid[i][j])?i:j;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(dp[i][j]==i)count++;
            }
            if(count==n)ans=i;
        }
        return ans;
    }
};