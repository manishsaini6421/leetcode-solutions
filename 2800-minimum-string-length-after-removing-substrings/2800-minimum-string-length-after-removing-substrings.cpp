class Solution {
public:
    int minLength(string s) {
        int i=0;
        while(i<s.size()){
            if((s[i]=='A' && s[i+1]=='B') || (s[i]=='C' && s[i+1]=='D')){
                
                s.erase(i,2);
                if(i!=0) i--;
            }
            else i++;
           
        }
        return s.size();
    }
};