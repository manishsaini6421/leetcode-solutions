class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        int digitCount=0;
        int n=s.size();
        for(int i=n-1; i>=0; i--){
            if(s[i]>='a' && s[i]<='z'){
                
                
                if(digitCount==0){
                    ans=s[i]+ans;
                    
                }
                else{
                    digitCount--;
                }
            }
            else{
                digitCount++;
            }
        }
        return ans;
    }
};