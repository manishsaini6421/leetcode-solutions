class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        int ans=1;
       for(int i=0; i<=15; i++){
            cout<<ans<<endl;
            if(ans==n)return true;
            if(ans<INT_MAX/4)
                ans*=4;
       }
        return false;
    }
};