class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int n=arr.size();
        int ans=0;
        for(int i=0; i<n; i++){
            
                dp[arr[i]]=1+dp[arr[i]-difference];
            
            ans=max(ans,dp[arr[i]]);
        }
       
        return ans;
    }
};