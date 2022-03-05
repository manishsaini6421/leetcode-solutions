class Solution {
public:
    string freqAlphabets(string s) {
        int n=s.size();
        string str;
        int i=0;
        while(i<n-2){
            if(s[i+2]=='#'){
            
                 str+=((s[i]-'0')*10+(s[i+1]-'0')*1)+96;
                 i+=3;
            }
            else{
                str+=(s[i]-'0')+96;
                i++;
            }
        }
        while(i<n){
           str+=(s[i]-'0')+96;
       i++;
        }
       
        
        return str;
    }
};