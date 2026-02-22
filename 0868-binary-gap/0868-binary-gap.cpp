class Solution {
public:
    int binaryGap(int n) {
        vector<int> v;
        int i=-1;
        while(n){
            i++;
            if(n&1){
                v.push_back(i);
            }
            
            n>>=1;
        }
        int ans=0;
        for(int i=1; i<v.size(); i++){
            ans=max(ans,v[i]-v[i-1]);
        }
        return ans;
    }
};