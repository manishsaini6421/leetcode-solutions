class Solution {
public:

    int solve(int i, int jump, int jumpType, int k,vector<vector<vector<int>>> &dp,vector<long long> &exp) {
        if (i > k + 1)
            return 0;

        int ans=0; 
        if (i == k) {
            ans++;
        }

        if(i<50 && dp[i][jump][jumpType]!=-1)return dp[i][jump][jumpType];

        
        

        int down = 0;
        if (jumpType && i>0)
            ans += solve(i - 1, jump, 0, k,dp,exp);

        ans += solve(i + exp[jump], jump + 1, 1, k,dp,exp);

        return (i<50)? dp[i][jump][jumpType]=ans:ans;
    }

    

    int waysToReachStair(int k) {
        vector<vector<vector<int>>> dp(40,vector<vector<int>> (40,vector<int> (2,-1)));

        vector<long long> exp(33);
        exp[0]=1;
        for(int i=1; i<33; i++){
            exp[i]=exp[i-1]*2;
        }
         return solve(1, 0, 1, k,dp,exp);
          }
};