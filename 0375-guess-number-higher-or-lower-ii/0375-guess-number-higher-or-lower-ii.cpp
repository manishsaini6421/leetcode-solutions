class Solution {
public:
    int solve(int i,int j){
        if(i>=j)return 0;
        int ans=INT_MAX;
        for(int k=i; k<=j; k++){
            ans=min(ans,k+max(solve(i,k-1),solve(k+1,j)));
        }
       
        return ans;
    }
    int getMoneyAmount(int n) {
       
                return solve(1,n);
    }
};