class Solution {
public:
static bool manual(string s1,string s2){
    return s1.size()<s2.size();
}
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        sort(words.begin(),words.end(),manual);
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(words[j].find(words[i])!=string::npos){
                    ans.push_back(words[i]);
                    break;
                }

                
            }
        }
        return ans;
    }
};