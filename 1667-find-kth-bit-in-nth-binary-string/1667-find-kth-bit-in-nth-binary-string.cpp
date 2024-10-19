class Solution {
public:
    string flip(string s){
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='1')s[i]='0';
            else s[i]='1';
        }
        return s;
    }
    string generate(int n){
        if(n==1) return "0";
        else if(n==2) return "011";
        string temp1=generate(n-1);
        string temp2=flip(temp1);
        reverse(temp2.begin(),temp2.end());
        return temp1+"1"+temp2;

    }
    char findKthBit(int n, int k) {
        string s=generate(n);
        return s[k-1];
        
    }
};