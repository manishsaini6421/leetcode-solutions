class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int> &dp){
        if(amount==0)return 0;
        if(amount<0)return INT_MAX;
        if(dp[amount]!=-1)return dp[amount];
        int n=coins.size();
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            int temp=solve(coins,amount-coins[i],dp);
           if(temp!=INT_MAX){
            ans=min(ans,temp+1);
           }
        }
        return dp[amount]=ans;

    }

    int solveTb(vector<int> &coins,int amount){
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=0; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j]<0 || dp[i-coins[j]]==INT_MAX)continue;
                else dp[i]=min(1+dp[i-coins[j]],dp[i]);
            }
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,-1);
        int ans=solveTb(coins,amount);
        return (ans==INT_MAX)?-1:ans;
    }
};