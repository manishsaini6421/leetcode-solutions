class Solution {
public:
    int minLength(string s) {
        int i=0;
        while(i<s.size()){
            if(i==0 && ((s[i]=='A' && s[i+1]=='B') || (s[i]=='C' && s[i+1]=='D'))){
                s.erase(i,2);
            }
            else if((s[i]=='A' && s[i+1]=='B') || (s[i]=='C' && s[i+1]=='D')){
                s.erase(i,2);
                i--;
                
            }
            // else if(s[i]=='C' && s[i+1]=='D'){
            //     s.erase(i,2);
            //     i--;
            // }
           else i++;
           
        }
        return s.size();
    }
};