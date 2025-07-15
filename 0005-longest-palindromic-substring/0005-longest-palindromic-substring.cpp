class Solution {
public:
    bool isPalindrome(string &s, int i,int j,vector<vector<int>> &dp){
        if(i>=j)return true;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j]) return dp[i][j]=isPalindrome(s,i+1,j-1,dp);
        return dp[i][j]=0;
      
    }
    
    pair<int,int> solve(string s){
        int n=s.size();
        int startIndex=0,maxLen=0;
        

        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int i=0; i<n; i++){
            for(int j=i; j>=0; j--)
            dp[i][j]=1;
        }

        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>i; j--){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                } 
                else dp[i][j]=0;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(dp[i][j]==1 && j-i+1>maxLen){
                    maxLen=j-i+1;
                    startIndex=i;
                }
            }
        }
        
        return {startIndex,maxLen};
    }
    string longestPalindrome(string s) {
        
        // int n=s.size();
        // int startIndex=0,maxLen=0;
        

        // vector<vector<int>> dp(n,vector<int> (n,-1));

        // for(int i=0; i<n; i++){
        //     dp[i][i]=1;
        // }

        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         if(isPalindrome(s,i,j,dp) && j-i+1>maxLen){
        //             maxLen=j-i+1;
        //             startIndex=i;
        //         }
        //     }
        // }
        
        // return s.substr(startIndex,maxLen);

        pair<int,int> p=solve(s);
        return s.substr(p.first,p.second);
    }
};