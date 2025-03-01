class Solution {
public:
    int solve(vector<int>& coins, int amount){
        if(amount==0)return 0;
        if(amount<0)return INT_MAX;
        int n=coins.size();
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            int temp=solve(coins,amount-coins[i]);
           if(temp!=INT_MAX){
            ans=min(ans,temp+1);
           }
        }
        return ans;

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans=solve(coins,amount);
        return (ans==INT_MAX)?-1:ans;
    }
};