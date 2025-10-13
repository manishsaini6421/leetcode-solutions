class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> freq(n,vector<int>(26,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<words[i].size(); j++){
                freq[i][words[i][j]-'a']++;
            }

        }

        vector<string> ans;
        for(int i=0; i<n; i++){
            ans.push_back(words[i]);
            for(int j=i+1; j<n; j++){
                int count=0;
                for(int k=0; k<26; k++){
                    if(freq[i][k]==freq[j][k])count++;
                }
                if(count!=26)break;
                else i++;
            }
            
        }
        return ans;
    }
};