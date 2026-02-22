class Solution {
public:
    int binaryGap(int n) {
        int ans=0;
        int curr=-1,prev=-1;
        while(n){
            curr++;
            if(n&1){
                if(prev!=-1)
                ans=max(ans,curr-prev);
                prev=curr;
            }
            
            n>>=1;
        }
        
        // for(int i=1; i<v.size(); i++){
        //     ans=max(ans,v[i]-v[i-1]);
        // }
        return ans;
    }
};