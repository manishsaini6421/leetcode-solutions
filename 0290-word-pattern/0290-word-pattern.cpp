class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int A[26]={0};
        for(char ch:pattern){
            A[ch-'a']++;
        }
        unordered_map<string,int> freq;
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss>>word){
            words.push_back(word);
            freq[word]++;
        }

        unordered_map<char,string> mapping;
        int n=pattern.size();
        if(n!=words.size())return false;
        for(int i=0; i<n; i++){
            if(mapping.find(pattern[i])!=mapping.end() && mapping[pattern[i]]!=words[i])return false;
            mapping[pattern[i]]=words[i];
        }
        for(int i=0; i<26; i++){
            if(A[i]!=0){
                bool flag=false;
                for(auto &fq:freq){
                    if(fq.second==A[i]){
                        flag=true;
                        fq.second=0;
                        break;
                    }
                }
                if(!flag)return false;
            }
        }
        return true;
    }
};