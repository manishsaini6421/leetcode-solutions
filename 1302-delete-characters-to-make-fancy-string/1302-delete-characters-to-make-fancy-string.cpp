class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        ans+=s[0];
        int count=1;
        for(int i=1; i<s.size(); i++){
            if(s[i]!=ans[ans.size()-1])
            {
                ans+=s[i];
                count=1;
            }
            else if(count<2){
                ans+=s[i];
                count++;
            }
        }
        return ans;
    }
};