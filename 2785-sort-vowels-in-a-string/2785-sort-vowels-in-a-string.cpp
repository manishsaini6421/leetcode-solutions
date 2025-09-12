class Solution {
public:

    bool isVovel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' ||c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                return true;
            }
            return false;
    }
    string sortVowels(string s) {
        map<char,int> mp;
        for(int i=0; i<s.size(); i++){
            if(isVovel(s[i]))
                mp[s[i]]++;
            

        }
        string temp="AEIOUaeiou";
        int index=0;
        for(int i=0; i<s.size(); i++){
            if(isVovel(s[i])){
                while(mp[temp[index]]==0){
                    index++;
                }
                s[i]=temp[index];
                mp[temp[index]]--;
            }

        }
        return s;
    }
};