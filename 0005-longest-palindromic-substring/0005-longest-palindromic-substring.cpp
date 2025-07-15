class Solution {
public:
    bool isPalindrome(string &s, int i,int j,vector<vector<int>> &dp){
        if(i>=j)return true;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j]) return dp[i][j]=isPalindrome(s,i+1,j-1,dp);
        return dp[i][j]=0;
      
    }

    string longestPalindrome(string s) {
        
        int n=s.size();
        int startIndex=0,maxLen=0;
        

        vector<vector<int>> dp(n,vector<int> (n,-1));

        for(int i=0; i<n; i++){
            dp[i][i]=1;
        }

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s,i,j,dp) && j-i+1>maxLen){
                    maxLen=j-i+1;
                    startIndex=i;
                }
            }
        }
        
        return s.substr(startIndex,maxLen);
    }
};