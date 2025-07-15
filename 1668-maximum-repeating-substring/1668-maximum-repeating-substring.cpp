class Solution {
public:
   
    int maxRepeating(string sequence, string word) {
        
        int ans=0;
        string str=word;
        while(sequence.find(word)!=string::npos){
            ans++;
            word+=str;
        }
        return ans;
    }
};