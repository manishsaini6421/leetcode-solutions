class Solution {
public:
    int minimumLength(string s) {
        vector<int> v(26,0);

        int n=s.size();
        for(int i=0; i<n; i++){
            v[s[i]-'a']++;
        }

        int ans=0;

        for(int i=0; i<26; i++){
            if(v[i]>0){
                if(v[i]%2==0)ans+=2;
                else ans+=1;
            }
            

        }
        return ans;
    }
};