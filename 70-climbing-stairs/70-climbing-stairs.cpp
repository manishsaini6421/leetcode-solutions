class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2) return n;
        int temp1=1;
        int temp2=1;
        int result=0;
        for(int i=2; i<=n; i++){
            result=temp1+temp2;
            temp2=temp1;
            temp1=result;
        }
        return result;
    }
};