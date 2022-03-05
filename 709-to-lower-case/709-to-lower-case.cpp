class Solution {
public:
    string toLowerCase(string s) {
        int n=s.size();
        string str="";
        for(int i=0; i<n; i++){
            if(s[i]<=90 && s[i]>=65){
                str+=(s[i]-'A')+97;
                
            }
            else if(s[i]>=97 && s[i]<=122){
                str+=s[i];
            }
            else{
                str+=s[i];
            }
        }
        return str;
    }
};