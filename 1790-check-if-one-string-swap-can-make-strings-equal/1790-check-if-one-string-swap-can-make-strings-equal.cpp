class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        string a1="",a2="";
        string b1="",b2="";
        int n=s1.size();
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i]){
                if(a1==""){
                     a1=s1[i];
                    a2=s2[i];
                }  
                else if(b1==""){
                    b1=s1[i];
                    b2=s2[i];
                }    
                else 
                    return false;
                                    
            }
            
        }
        if(a1==b2 && a2==b1)
            return true;
        return false;
    }
};