class Solution {
public:
     
    int solve(int i,int j, vector<vector<int>>& triangle,map<array<int,2>,int> &dp){
        int n=triangle.size();
        if(i==n-1)return triangle[i][j];

        if(dp.count({i,j}))return dp[{i,j}];
        int down=triangle[i][j]+solve(i+1,j,triangle,dp);

        int diagonal=triangle[i][j]+solve(i+1,j+1,triangle,dp);

        return dp[{i,j}]=min(down,diagonal);

    }
    // int solveTab(vector<vector<int>>& triangle){
    //     int n=triangle.size();
    //     map<array<int,2>,int> dp;
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        map<array<int,2>,int> dp;
        return solve(0,0,triangle,dp);
    }
};