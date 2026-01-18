class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans="";
        int c=0;
        int i=num1.size()-1,j=num2.size()-1;
        while(i>=0 && j>=0){
            int x= (num1[i]-'0')+(num2[j]-'0')+c;
            ans=to_string(x%10)+ans;
            c=x/10;
            i--;
            j--;
        }
        while(i>=0){
            int x= (num1[i]-'0')+c;
            ans=to_string(x%10)+ans;
            c=x/10;
            i--;
        }
        while(j>=0){
            int x= (num2[j]-'0')+c;
            ans=to_string(x%10)+ans;
            c=x/10;
            j--;
        }
        if(c>0)ans=to_string(c)+ans;
        return ans;
    }
};