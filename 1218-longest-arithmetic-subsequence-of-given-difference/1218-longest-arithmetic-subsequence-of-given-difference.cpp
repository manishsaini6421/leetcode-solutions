class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int n=arr.size();
        int ans=0;
        for(int i=0; i<n; i++){
            if(dp.count(arr[i]-difference)){
                dp[arr[i]]=1+dp[arr[i]-difference];
            }
            else{
                dp[arr[i]]=1;
            }
            ans=max(ans,dp[arr[i]]);
        }
        // int ans=0;
        // for(auto num:dp){
        //     ans=max(ans,num.second);
        // }
        return ans;
    }
};