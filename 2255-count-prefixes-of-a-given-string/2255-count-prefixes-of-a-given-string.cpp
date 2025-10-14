class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        vector<string> temp;
        for(int i=1; i<=s.size(); i++){
            string st=s.substr(0,i);
            temp.push_back(st);
        }
        int count=0;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<temp.size(); j++){
                if(words[i]==temp[j])count++;
            }
        }
        return count;
    }
};