class Solution {
public:
    double power(double x,int n){
        if(n==0)return 1;
        double temp=power(x,n/2);
        return (n%2)?(temp*temp*x):temp*temp;
    }
    double myPow(double x, int n) {
        return (n<0)?1/power(x,n):power(x,n);
    }
};