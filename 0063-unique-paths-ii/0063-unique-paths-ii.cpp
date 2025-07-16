class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int i,int j){
        if(obstacleGrid[0][0]==1)return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        if(i==m-1 && j==n-1){
            if(obstacleGrid[i][j]==0)return 1;
            return 0;
        }

        int right=0;
        if(j<n-1 && obstacleGrid[i][j+1]==0){
            right=solve(obstacleGrid,i,j+1);
        }
        int down=0;
        if(i<m-1 && obstacleGrid[i+1][j]==0){
            down=solve(obstacleGrid,i+1,j);
        }
        return right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return solve(obstacleGrid,0,0);
    }
};