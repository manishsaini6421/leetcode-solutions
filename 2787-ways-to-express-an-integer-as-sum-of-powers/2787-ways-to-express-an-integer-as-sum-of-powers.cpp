#define MOD 1000000007
class Solution {
public:
    int solve(int i,int sum,int n, vector<int> &powers,vector<vector<int>> &dp){
        int size=powers.size();
         if(sum==n)return 1;
        
        if(i>=size || sum>n)return 0;
       
        if(dp[i][sum]!=-1)return dp[i][sum];

        int take=solve(i+1,sum+powers[i],n,powers,dp);
        int dontTake=solve(i+1,sum,n,powers,dp);

        return dp[i][sum]=(take+dontTake)%MOD;

    }
    int numberOfWays(int n, int x) {
        vector<int> powers;
        int temp=1;
        while(pow(temp,x) <= n){
            powers.push_back(pow(temp,x));
            temp++;
        }
        int size=powers.size();

        vector<vector<int>> dp(size,vector<int>(n,-1));
        return solve(0,0,n,powers,dp);
    }
};