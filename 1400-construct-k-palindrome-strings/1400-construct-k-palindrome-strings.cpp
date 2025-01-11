class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;
        vector<int> v(26,0);

        for(int i=0; i<s.size(); i++){
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