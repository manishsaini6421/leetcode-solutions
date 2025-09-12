class Solution {
public:
    string sortVowels(string s) {
        map<char,int> mp;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' ||s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                mp[s[i]]++;
            }

        }
        string temp="AEIOUaeiou";
        int index=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' ||s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
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