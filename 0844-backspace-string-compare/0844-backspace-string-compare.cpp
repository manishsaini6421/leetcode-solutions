class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> v1,v2;
        for(int i=0; i<s.size(); i++){
            if(v1.size()>0 && s[i]=='#')v1.pop_back();
            else if(s[i]=='#')continue;
            else v1.push_back(s[i]);
        }
        string s1="";
        for(int i=0; i<v1.size(); i++){
            s1+=v1[i];
        }
        for(int i=0; i<t.size(); i++){
            if(v2.size()>0 && t[i]=='#')v2.pop_back();
            else if(t[i]=='#')continue;
            else v2.push_back(t[i]);
        }
        string s2="";
        for(int i=0; i<v2.size(); i++){
            s2+=v2[i];
        }
        return s1==s2;
    }
};