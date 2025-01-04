class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> v(676,0);
        vector<vector<int>>m(26,vector<int>(2,-1));
        for(int i=0; i<s.size(); i++){
            if(m[s[i]-'a'][0]==-1)
                m[s[i]-'a'][0]=i;
        }
        for(int i=s.size()-1; i>=0; i--){
            if(m[s[i]-'a'][1]==-1)
                m[s[i]-'a'][1]=i;
        }
        for(int i=0; i<s.size()-1; i++){
            for(int j=0; j<26; j++){
                if(m[j][0]<i && m[j][1]>i)
                    v[26*j+s[i]-'a']=1;
            }
        }
        int count=0;
        for(int i=0; i<676; i++){
            if(v[i])count++;
        }
        return count;
    }
};