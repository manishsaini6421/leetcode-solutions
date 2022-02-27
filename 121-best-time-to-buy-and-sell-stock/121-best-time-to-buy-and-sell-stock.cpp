class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxRes=0,min=100001;
        for(int i=0; i<n; i++){
            if(min>prices[i]){
                min=prices[i];
            }
            if(maxRes < prices[i]-min){
                maxRes=prices[i]-min;
            }
        }
        return maxRes;
    }
};