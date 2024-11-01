class Solution {
public:
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
      
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        
       vector<int> fact;
       for(auto pair:factory){
        fact.insert(fact.end(),pair[1],pair[0]);
       }
        int m=robot.size();
        int n=fact.size();

        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));

        for(int i=0; i<m; i++){
            dp[i][n]=1e12;
        }

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                long long take=abs(robot[i]-fact[j])+dp[i+1][j+1];
                long long dontTake=dp[i][j+1];

                dp[i][j]=min(take,dontTake);
            }
        }
        return dp[0][0];
    }
};