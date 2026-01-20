class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        int n=strs.size(),count=0;
        for(int j=0; j<strs[0].size(); j++){
            for(int i=0; i<n; i++){
                if(strs[0][j]==strs[i][j])count++;
                
            }
            if(count==n){
                s+=strs[0][j];
                count=0;
            }
            else break;
        }
        return s;
    }
};