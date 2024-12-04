class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int count=0;
        int n=searchWord.size();
        while(ss >> word){
            int m=word.size();
            int i=0;
            while(i<n && i<m){
                if(searchWord[i]==word[i]) i++;
                else break;
                
            }
            count++;
            if(i==n)return count;
        }
        return -1;
    }
};