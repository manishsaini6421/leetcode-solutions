class Solution {
public:
    
    pair<int,int> solve(string s){
      
        int n=s.size();
        int startIndex=0,maxLen=0;
        

        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int i=0; i<n; i++){
            for(int j=i; j>=0; j--){
                dp[i][j]=1;
            }
            
        }

        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=i; j--){
                if(s[i]==s[j]){
                    if(j>0)
                    dp[i][j]=dp[i+1][j-1];
                    
                } 
                else dp[i][j]=0;
                if(dp[i][j]==1 && j-i+1>maxLen){
                    
                    maxLen=j-i+1;
                    startIndex=i;
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         if(dp[i][j]==1 && j-i+1>maxLen){
        //             maxLen=j-i+1;
        //             startIndex=i;
        //         }
        //     }
        // }
        
        return {startIndex,maxLen};
    }
    string longestPalindrome(string s) {
        
        

        pair<int,int> p=solve(s);
        return s.substr(p.first,p.second);
    }
};