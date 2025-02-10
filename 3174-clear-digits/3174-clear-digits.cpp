class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        int charCount=0;
        int digitCount=0;
        int n=s.size();
        for(int i=n-1; i>=0; i--){
            if(s[i]>='a' && s[i]<='z'){
                
                charCount++;
                if(digitCount<charCount){
                    ans=s[i]+ans;
                    charCount--;
                }
                else{
                    charCount--;
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