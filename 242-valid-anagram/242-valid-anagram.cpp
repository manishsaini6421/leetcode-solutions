class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
       map<char,int> m1;
        map<char,int> m2;
        for(int i=0; i<s.size(); i++){
            m1[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            m2[t[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            if(m1[t[i]]==0)
                return false;
            if(m1[t[i]] != m2[t[i]])
                return false;
        }
        return true;
    }
};