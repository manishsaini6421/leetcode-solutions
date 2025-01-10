class Solution {
public:
    int minimizedStringLength(string s) {
        map<char,int> m;
        int n=s.size();
        for(int i=0; i<n; i++){
            m[s[i]]++;
        }
        return m.size();
    }
};