class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        int n=prices.size();
        for(int i=0; i<n; i++){
            int flag=0;
            for(int j=i+1; j<n; j++){
                if(prices[i]>=prices[j]){
                    ans.push_back(prices[i]-prices[j]);
                    flag=1;
                    break;
                }
            }
            if(!flag)ans.push_back(prices[i]);
        }
        return ans;
    }
};