class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int ans=0,j=0,k=0;
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            if(mp['a'] && mp['b'] && mp['c']){
                while(mp['a'] && mp['b'] && mp['c']){
                    mp[s[j]]--;
                    j++;
                }
                ans+=(n-i+j-k-1 + (j-k-1)*(n-i-1));
                k=j;
            }
           
            
        }
        return ans;
    }
};