class Solution {
public:
    string flip(string s){
        int n=s.size();
        string s1="";
        for(int i=n-1; i>=0; i--){
            if(s[i]=='1')s1+='0';
            else s1+='1';
        }
        return s1;
    }
    string generate(int n){
        if(n==1) return "0";
        else if(n==2) return "011";
        string temp1=generate(n-1);
        string temp2=flip(temp1);
        // reverse(temp2.begin(),temp2.end());
        return temp1+"1"+temp2;

    }
    char findKthBit(int n, int k) {
        string s=generate(n);
        return s[k-1];
        
    }
};