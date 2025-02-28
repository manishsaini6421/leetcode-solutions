class Solution {
public:
    
    int lenLongestFibSubseq(vector<int>& arr) {
       unordered_map<int,int> map;
       int n=arr.size();
       for(int i=0; i<n; i++){
            map[arr[i]]=i;
       }
       vector<vector<int>> dp(n,vector<int> (n,0));
      
       int ans=0;
       for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            int diff=arr[i]-arr[j];
            int prevIndex=(map.find(diff)!=map.end())?map[diff]:-1;
            if(prevIndex<j && prevIndex>-1){
                dp[i][j]=dp[j][prevIndex]+1;
            }
            else dp[i][j]=2;
            ans=max(ans,dp[i][j]);
        }
       }
        
        return ans;

    }
};