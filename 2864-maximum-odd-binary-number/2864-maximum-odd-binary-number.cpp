class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]=='1')i++;
            if(s[j]=='0')j--;
            if(s[i]=='0' && s[j]=='1'){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='1'){
                swap(s[i],s[s.size()-1]);
                break;
            }
        }
        return s;
    }
};