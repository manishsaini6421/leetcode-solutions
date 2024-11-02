class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream iss(sentence);
        string word;

        vector<string> v;

        while(iss>>word){
            v.push_back(word);
        }
        if(v.size()==1){
            return v[0][v[0].size()-1]==v[0][0];
        }
        for(int i=1; i<v.size(); i++){
            if(v[i-1][v[i-1].size()-1]!=v[i][0]) return false;
        }
        if(v[v.size()-1][v[v.size()-1].size()-1]!=v[0][0])return false;
        return true;
    }
};