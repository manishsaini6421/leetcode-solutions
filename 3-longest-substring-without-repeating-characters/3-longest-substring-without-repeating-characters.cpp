class Solution {
public:
    int lengthOfLongestSubstring(string s) {
  vector<int> v(128,0);
        int i=0,j=0;
        int n=s.size();
        int maxlen=0;
        while(j<n){
            if(v[s[j]]==0){
                maxlen=max(maxlen,j-i+1);
                v[s[j]]=1;
                j++;
            }
            else{
                i++;
                j=i;
                fill(v.begin(),v.end(),0);
            }
        }
        return maxlen;
    }
};