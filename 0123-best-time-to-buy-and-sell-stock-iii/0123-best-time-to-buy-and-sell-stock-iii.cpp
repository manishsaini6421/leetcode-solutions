class Solution {
public:
    int solve(int index,int flag,int limit,vector<int>& prices){
        if(index==prices.size())return 0;
        if(limit==0)return 0;
        int buy=0;
        int sell=0;
        if(flag){
            buy=solve(index+1,0,limit,prices)-prices[index];
        }
        
        else{
            sell=prices[index]+solve(index+1,1,limit-1,prices);
        }
        int skip=solve(index+1,flag,limit,prices);

        return max(skip,max(buy,sell));
    }
    int maxProfit(vector<int>& prices) {
        return solve(0,1,2,prices);

    }
};