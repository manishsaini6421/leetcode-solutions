class Solution {
public:
    
    int solve(vector<vector<int>>& cuboids, int index, vector<int>& prev) {
        if (index == cuboids.size())
            return 0;

        int w = cuboids[index][0], l = cuboids[index][1],h = cuboids[index][2];
        
        int include=0;

        if(w>=prev[0] && l>=prev[1] && h>=prev[2]){
            include=h+solve(cuboids,index+1,cuboids[index]);
        }
        int exclude=solve(cuboids,index+1,prev);

        return max(include,exclude);
    }

    int solveIndex(vector<vector<int>>& cuboids, int curr, int prev) {
        if (curr == cuboids.size())
            return 0;

        int w = cuboids[curr][0], l = cuboids[curr][1],h = cuboids[curr][2];
        
        int include=0;

        if(prev==-1 || w>=cuboids[prev][0] && l>=cuboids[prev][1] && h>=cuboids[prev][2]){
            include=h+solveIndex(cuboids,curr+1,curr);
        }
        int exclude=solveIndex(cuboids,curr+1,prev);

        return max(include,exclude);
    }

    int solveMem(vector<vector<int>>& cuboids, int curr, int prev,vector<vector<int>> &dp) {
        if (curr == cuboids.size())
            return 0;
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        int w = cuboids[curr][0], l = cuboids[curr][1],h = cuboids[curr][2];
        
        int include=0;

        if(prev==-1 || w>=cuboids[prev][0] && l>=cuboids[prev][1] && h>=cuboids[prev][2]){
            include=h+solveMem(cuboids,curr+1,curr,dp);
        }
        int exclude=solveMem(cuboids,curr+1,prev,dp);

        return dp[curr][prev+1]=max(include,exclude);
    }

    int solveTab(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int w = cuboids[curr][0], l = cuboids[curr][1],h = cuboids[curr][2];
        
                int include=0;

                if(prev==-1 || w>=cuboids[prev][0] && l>=cuboids[prev][1] && h>=cuboids[prev][2]){
                    include=h+dp[curr+1][curr+1];
                }
                int exclude=dp[curr+1][prev+1];

               dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
        
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid:cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());

        // vector<int> v={0,0,0};
        // return solve(cuboids,0,v);

        //return solveIndex(cuboids,0,-1);
        
        // int n=cuboids.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solveMem(cuboids,0,-1,dp);

        int n=cuboids.size();
        return solveTab(cuboids);
          
    }
};