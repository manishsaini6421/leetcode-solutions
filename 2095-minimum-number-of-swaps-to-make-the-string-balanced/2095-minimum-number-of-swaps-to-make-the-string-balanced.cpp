class Solution {
public:
    int minSwaps(string s) {
       long int open=0,close=0,res=0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='[')open++;
            else if(s[i]==']' && open>0)open--;
            
            
        }
        
        return (open+1)/2;
    }
};