class Solution {
public:
    bool isVovel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return true;
        return false;
    }
    int maxFreqSum(string s) {
        int arr[26]={0};
        for(int i=0; i<s.size(); i++){
            arr[s[i]-'a']++;
        }

        int maxVovel=0,maxConsonent=0;
        for(int i=0; i<26; i++){
            if(isVovel(i+'a')){
                maxVovel=max(maxVovel,arr[i]);
            }
            else{
                maxConsonent=max(maxConsonent,arr[i]);
            }
        }

        return maxVovel+maxConsonent;
    }
};