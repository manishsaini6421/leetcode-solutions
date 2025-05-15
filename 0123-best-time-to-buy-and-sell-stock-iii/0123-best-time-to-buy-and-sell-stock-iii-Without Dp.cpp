class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> profit(n+1,0);
        int maxi=prices[n-1];

        for(int i=n-1; i>=0; i--){
            profit[i]=max(profit[i+1],maxi-prices[i]);
            maxi=max(maxi,prices[i]);

        }
       
        int mini=prices[0];
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans,prices[i]-mini+profit[i+1]);
            mini=min(mini,prices[i]);
        }
        return ans;

    }
};