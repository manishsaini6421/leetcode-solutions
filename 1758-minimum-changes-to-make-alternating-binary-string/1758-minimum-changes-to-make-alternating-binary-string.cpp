class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int zero=0,one=0;
        for(int i=0; i<n; i++){
            if(i%2 && s[i]=='0')zero++;
            if(i%2==0 && s[i]=='1')zero++;
        }
        for(int i=0; i<n; i++){
            if(i%2 && s[i]=='1')one++;
            if(i%2==0 && s[i]=='0')one++;
        }
        cout<<one<<" "<<zero;
        return min(zero,one);
    }
};