class Solution {
public:
    int balancedStringSplit(string s) {
        int r=0,l=0,n=s.size();
        int ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='R')r++;
            else l++;
            if(r==l){
                ans++;
                r=0;
                l=0;
            }
        }
        return ans;
    }
};