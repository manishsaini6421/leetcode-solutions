class Solution {
public:
    int solve(int i,int j, string &text1, string &text2){
        if(i==text1.size() || j==text2.size())return 0;
        int length=0;
        if(text1[i]==text2[j]){
            length=1+solve(i+1,j+1,text1,text2);
        }
        else{
            length=max(solve(i+1,j,text1,text2),solve(i,j+1,text1,text2));
        }
        return length;
    }

    int solveMem(int i,int j, string &text1, string &text2,vector<vector<int>> &dp){
        if(i==text1.size() || j==text2.size())return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        int length=0;
        if(text1[i]==text2[j]){
            length=1+solveMem(i+1,j+1,text1,text2,dp);
        }
        else{
            length=max(solveMem(i+1,j,text1,text2,dp),solveMem(i,j+1,text1,text2,dp));
        }
        return dp[i][j]=length;
    }
    int longestCommonSubsequence(string text1, string text2) {
    
        //return solve(0,0,text1,text2);

        int m=text1.size();
        int n=text2.size();

        vector<vector<int>> dp(m+1,vector<int> (n,-1));

        return solveMem(0,0,text1,text2,dp);
        
    }
};