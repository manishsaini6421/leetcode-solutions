class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string res="",s1="";
        for(int i=0; i<n; i++){
            
            if(s[i]==' '){
                res=res+s1+" ";
                s1="";
                continue;
            }
            s1=s[i]+s1;
        }
         res=res+s1;
        return res;
    }
};