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


        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                int count=0;
                for(int k=0; k<26; k++){
                    if(freq[i][k]==freq[j][k])count++;
                }
                if(count==26){
                    words.erase(words.begin()+j);
                    freq.erase(freq.begin()+j);
                    j--;
                }
            }
        }
        return words;
    }
};