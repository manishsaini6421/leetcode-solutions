class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        int n=words.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int size1=words[i].size();
                 int size2=words[j].size();
                if(size1<=size2){
                    if(words[j].substr(0,size1)==words[i] && words[j].substr(size2-size1,size1)==words[i])ans++;
                }
            }
        }
        return ans;
    }
};