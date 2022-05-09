class Solution {
public:
    int fib(int n) {
        int memo[31];
        memo[0]=0;
        memo[1]=1;
        for(int i=2; i<=30; i++){
            memo[i]=memo[i-1]+memo[i-2];
        }
        return memo[n];
    }
};