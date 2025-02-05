class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count=0;
        int n=s1.size();
        map<char,int> m1,m2;
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i])count++;
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        for(int i=0; i<26; i++){
            if(m1['a'+i]!=m2['a'+i])return false;
        }
        if(count<=2)return true;
        return false;
    }
};