class Solution {
public:
     
    int solve(int i,int j, vector<vector<int>>& triangle){
        int n=triangle.size();
        if(i==n-1)return triangle[i][j];

        int down=triangle[i][j]+solve(i+1,j,triangle);

        int diagonal=triangle[i][j]+solve(i+1,j+1,triangle);

        return min(down,diagonal);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(0,0,triangle);
    }
};