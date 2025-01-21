class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<vector<int>> v1(2,vector<int> (n,0));
        v1[0][n-1]=grid[0][n-1];
        v1[1][n-1]=grid[1][n-1];
        for(int i=n-2; i>=0; i--){
            v1[0][i]=grid[0][i]+v1[0][i+1];
             v1[1][i]=grid[1][i]+v1[1][i+1];
        }
      
        int i=0,j=0;
        while(i<n){
            grid[j][i]=0;
            if(j<1 && i<n-1 && v1[0][i+1]<v1[1][i]+grid[0][i])
                     j++;

            else 
             i++;
        }
        grid[1][n-1]=0;
        vector<vector<int>> v2(2,vector<int> (n,0));
        v2[0][n-1]=grid[0][n-1];
        v2[1][n-1]=grid[1][n-1];
        for(int i=n-2; i>=0; i--){
            v2[0][i]=grid[0][i]+v2[0][i+1];
             v2[1][i]=grid[1][i]+v2[1][i+1];
        }
        
          cout<<v2[0][0]<<" "<<v2[1][0];
        i=0,j=0;
        int ans=0;
        while(i<n){
            ans+=grid[j][i];
            grid[j][i]=0;
            if(j<1 && i<n-1 && v2[0][i+1]<v2[1][i]+grid[0][i])
                     j++;

            else
             i++;
        }
        return ans;
    }
};