class Solution {
public:
    int myAtoi(string s) {
        int ct=0,count=0;

        string res="";
        for(int i=0; i<s.size(); i++){
            
            if(s[i]==' ' && count!=1)
            continue;
            else if(s[i]=='-' && count!=1 && !(ct==-1 || ct==1)){
                ct=-1; count=1;
            }
            
            else if(s[i]=='+' && count!=1 && !(ct==-1 || ct==1)){
               ct=1;
               count=1;
            }
           
            else if(s[i]>='0' && s[i]<='9'){
               res+=s[i];
               count=1;
            }
            else
            break;
        }
        string new_res="";
        int t=0;
        for(int i=0; i<res.size(); i++){
             if(res[i]=='0' && t==0)
             continue;
             else{
                t=1;
                new_res+=res[i];
             }
        }
        cout<<res<<endl;
       long long int n=1 ,result=0;
        for(int i=new_res.size()-1; i>=0; i--){
            
           result+=(new_res[i]-'0')*n;
           if(n<INT_MAX)            
           n*=10;

        }
        if(ct==-1) 
        result=result*-1;
        if(result<-2147483648)return -2147483648;
        if (result >INT_MAX) return INT_MAX;
        
        return result;
    }
};