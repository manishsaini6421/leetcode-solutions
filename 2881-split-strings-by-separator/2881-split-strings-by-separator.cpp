class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        int n=words.size();
        vector<string> res;
        for(int i=0; i<n; i++){
            string s="";
            int m=words[i].size();
            for(int j=0; j<=m; j++){
                if(words[i][j]==separator && s!="") {
                    res.push_back(s);
                    s="";
                }
                else if(words[i][j]=='\0' && s!="")res.push_back(s);
                else if(words[i][j]!=separator) s+=words[i][j];
            }
        }
        return res;
    }
};