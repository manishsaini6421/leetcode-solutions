class Solution {
public:
    bool find(string s, char x){
        for(char ch:s){
            if(ch==x)return true;
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0; i<words.size(); i++){
            if(find(words[i],x))ans.push_back(i);
        }
        return ans;
    }
};