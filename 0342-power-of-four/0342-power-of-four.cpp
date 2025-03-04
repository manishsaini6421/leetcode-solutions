class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        int zeroCount=0;
        int oneCount=0;
        while(n>0){
            if(n&1)oneCount++;
            else zeroCount++;
            n>>=1;
        }
        if(oneCount==1 && zeroCount%2==0)return true;
        return false;
    }
};