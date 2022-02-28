class Solution {
public:
    bool isHappy(int n) {
        int t=15;
        while(n!=1 && t>0){
            string s=to_string(n);
            n=0;
            for(int i=0; i<s.size(); i++){
                n+=(s[i]-'0')*(s[i]-'0');
            }
           t--;
        }
        if(n==1)
            return true;
        return false;
    }
};