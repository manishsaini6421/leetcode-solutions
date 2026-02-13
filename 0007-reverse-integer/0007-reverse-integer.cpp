class Solution {
public:
    int reverse(int x) {
        int ans=0;
        while(x){
            if(ans*1l*10+(x%10) > INT_MAX || ans*1l*10+(x%10)<INT_MIN)return 0;
            ans=(ans*10)+(x%10);
            x/=10;
        }
        return ans;
    }
};