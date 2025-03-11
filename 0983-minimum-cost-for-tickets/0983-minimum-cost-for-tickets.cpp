class Solution {
public:
    int solveOpt(int n,vector<int> &days, vector<int> &cost){
    queue<pair<int,int>> week;
    queue<pair<int,int>> month;

    int ans=0;

    for(auto day:days){
        
        while(!week.empty() && week.front().first<=day-7)
            week.pop();
        while(!month.empty() && month.front().first<=day-30)
            month.pop();

        week.push({day,ans+cost[1]});
        month.push({day,ans+cost[2]});

        ans=min(ans+cost[0],min(week.front().second,month.front().second)) ;      
    }

    return ans;
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solveOpt(days.size(),days,costs);
    }
};