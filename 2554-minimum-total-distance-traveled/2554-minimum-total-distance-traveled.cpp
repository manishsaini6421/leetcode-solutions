class Solution {
public:
    long long fun(vector<int>& robot,vector<int>& factory,int robotIndex,int factIndex,vector<vector<long long>>&dp){
         if(robotIndex==robot.size())return 0;
        if(factIndex==factory.size())return 1e12;

        if(dp[robotIndex][factIndex]!=-1)return dp[robotIndex][factIndex];

        long long pick=abs(robot[robotIndex]-factory[factIndex])+fun(robot,factory,robotIndex+1,factIndex+1,dp);
        long long notpick=fun(robot,factory,robotIndex,factIndex+1,dp);

        return dp[robotIndex][factIndex]=min(pick,notpick);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
      
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
       vector<int> fact;
       for(auto pair:factory){
        fact.insert(fact.end(),pair[1],pair[0]);
       }

         vector<vector<long long>> dp(robot.size()+1,vector<long long>(fact.size()+1,-1));
        cout<<fact.size()<<endl;
        return fun(robot,fact,0,0,dp);
    }
};