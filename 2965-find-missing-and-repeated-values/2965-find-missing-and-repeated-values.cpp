#define sqr(n) n*n
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        long long sum=0,sqrSum=0,s=sqr(n);
        long long actualSum=(s%2)?s*((s+1)/2):(s/2)*(s+1);
        long long actualSqrSum=s*(s+1)*(2*s+1)/6;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum+=grid[i][j];
                sqrSum+=grid[i][j]*grid[i][j];
            }
        }

        vector<int> ans(2,0);
        ans[1]=(actualSum-sum +(actualSqrSum-sqrSum)/(actualSum-sum))/2;
        ans[0]=ans[1]-actualSum+sum;
        return ans;
    }
};