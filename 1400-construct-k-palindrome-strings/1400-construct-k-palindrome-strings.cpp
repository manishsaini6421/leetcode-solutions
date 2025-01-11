class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();

        if(n<k)return false;
        vector<int> v(26,0);

        for(int i=0; i<n; i++){
            v[s[i]-'a']++;
        }
        int count=0;
        for(int i=0; i<26; i++){
            if(v[i]%2!=0)count++;
        }
        if(count<=k)return true;
        return false;
    }
};