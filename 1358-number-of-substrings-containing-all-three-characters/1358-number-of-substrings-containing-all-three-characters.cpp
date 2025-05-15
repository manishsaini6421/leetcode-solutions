class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int ans=0,j=0;
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            if(mp['a'] && mp['b'] && mp['c']){
                int skip=0;
                while(mp['a'] && mp['b'] && mp['c']){
                    mp[s[j]]--;
                    j++;
                    skip++;
                }
                ans+=(n-i+skip-1 + (skip-1)*(n-i-1));
            }
           
            
        }
        return ans;
    }
};