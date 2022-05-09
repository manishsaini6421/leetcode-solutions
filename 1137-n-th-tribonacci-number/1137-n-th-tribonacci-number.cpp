class Solution {
public:
    int tribonacci(int n) {
        int memo[38];
        memo[0]=0;
        memo[1]=1;
        memo[2]=1;
        for(int i=3; i<=37; i++){
            memo[i]=memo[i-1]+memo[i-2]+memo[i-3];
        }
          
        return memo[n];
    }
};