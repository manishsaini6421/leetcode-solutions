class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        string tmp="";
        string ans="";
        for(int i=0; i<n; i++){
            tmp+=num[i];
            if((num[i]-'0')%2)ans=tmp;

        }
        return ans;
    }
};