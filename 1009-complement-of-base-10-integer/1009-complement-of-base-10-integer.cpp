class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int ans=0,temp=1;
        while(n){
            ans=(n&1)?ans:temp+ans;
            temp*=2;
            n>>=1;
        }
        return ans;
    }
};