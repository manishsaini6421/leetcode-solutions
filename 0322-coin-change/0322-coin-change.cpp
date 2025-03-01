class Solution {
public:
    int solveTb(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
                    dp[i]=min(1+dp[i-coins[j]],dp[i]);
            }
        }
        
        return (dp[amount]==INT_MAX)?-1:dp[amount];
        
    }

    int coinChange(vector<int>& coins, int amount) {

       
        int ans = solveTb(coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }
};