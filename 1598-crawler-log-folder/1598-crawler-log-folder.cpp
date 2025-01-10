class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        string current="";
        for(int i=0; i<logs.size(); i++){

            if(logs[i].size()>2 && logs[i][logs[i].size()-2]=='.' && logs[i][logs[i].size()-3]=='.' && ans>0)ans--;
            else if(logs[i][logs[i].size()-2]=='.')continue;
            else ans++;

        }
        return ans;
    }
};