#define MOD 1000000007
class Solution {
public:
    int pow(int a,long long n){
        if(n==0)return 1;
        if(n==1)return a;
        int x=pow(a,n/2)%MOD;

        return (n%2==0)?(x*1l*x)%MOD:((x*1l*x)%MOD)*a%MOD;
    }
    int countGoodNumbers(long long n) {
      int ans=1;
      
      int x=pow(5,n/2)%MOD;
      int y=pow(4,n/2)%MOD;

      ans = (x*1l*y)%MOD;

      return (n%2==0)?ans:(ans*1l*5)%MOD;
    }
};