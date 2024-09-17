class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> count;
        istringstream iss1(s1);
        string word;
        while(iss1 >> word){
            count[word]++;
        }
        istringstream iss2(s2);
        while(iss2 >> word){
            count[word]++;
        }
        
        vector<string> result;
        for(const auto& pair:count){
            if(pair.second==1){
                result.push_back(pair.first);
            }
        }
        return result;
    }
};