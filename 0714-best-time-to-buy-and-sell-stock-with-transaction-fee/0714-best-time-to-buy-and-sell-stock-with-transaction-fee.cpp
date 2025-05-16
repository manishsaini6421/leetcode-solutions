class Solution {
public:
    int solve(int index, int flag,vector<int>& prices,int fee){
        if(index==prices.size())return 0;

        int buy=0;
        int sell=0;
        if(flag){
            buy=solve(index+1,0,prices,fee)-prices[index]-fee;
        }
        else{
            sell=prices[index]+solve(index+1,1,prices,fee);
        }

        int skip=solve(index+1,flag,prices,fee);

        return max(skip,max(buy,sell));

    }

     int solveMem(int index, int transactionNo,vector<int>& prices,int fee){
        if(index==prices.size())return 0;

        int buy=0;
        int sell=0;
        if(transactionNo%2==0){
            buy=solveMem(index+1,transactionNo+1,prices,fee)-prices[index]-fee;
        }
        else{
            sell=prices[index]+solveMem(index+1,transactionNo+1,prices,fee);
        }

        int skip=solveMem(index+1,transactionNo,prices,fee);

        return max(skip,max(buy,sell));

    }
    int maxProfit(vector<int>& prices, int fee) {
        return solve(0,1,prices,fee);

        int n=prices.size();

    }
};