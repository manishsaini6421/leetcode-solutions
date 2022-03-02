class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0; i<ransomNote.size(); i++){
            m1[ransomNote[i]]++;
        }
        for(int i=0; i<magazine.size(); i++){
            m2[magazine[i]]++;
        }
        
        for(int i=0; i<ransomNote.size(); i++){
        if(m2[ransomNote[i]]==0)
            return false;
        if(m1[ransomNote[i]] > m2[ransomNote[i]]){
                return false;
            }
            
        }
        return true;
    }
};