class Solution {
public:
    int solve(int amount,vector<int>& coins,int prev){
        if(amount==0)return 1;
        if(amount<0)return 0;
        int ans=0;
        for(int i=prev; i<coins.size(); i++){
            ans+=solve(amount-coins[i],coins,i);
        }
        return ans;
    }
    int change(int amount, vector<int>& coins) {
        return solve(amount,coins,0);
    }
};