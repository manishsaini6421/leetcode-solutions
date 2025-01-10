class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n=words1.size();
        int m=words2.size();
        vector<string> ans;
        vector<vector<int>> v1(n,vector<int>(26,0));
        vector<vector<int>> v2(m,vector<int>(26,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<words1[i].size(); j++){
                v1[i][words1[i][j]-'a']++;
            }
        }
         for(int i=0; i<m; i++){
            for(int j=0; j<words2[i].size(); j++){
                v2[i][words2[i][j]-'a']++;
            }
        }
        vector<int> v3;
        for(int i=0; i<26; i++){
            int maxcount=INT_MIN;
            for(int j=0; j<m; j++){
                maxcount=max(v2[j][i],maxcount);
            }
            cout<<maxcount<<endl;
            v3.push_back(maxcount);
        }
        for(int i=0; i<n; i++){
            int flag=0;
            for(int j=0; j<26; j++){
                if(v1[i][j]>=v3[j])continue;
                else{
                    flag=1;
                    break;
                }
            }
            if(!flag)ans.push_back(words1[i]);
        }
        return ans;
    }
};