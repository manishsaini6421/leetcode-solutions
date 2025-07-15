class Solution {
public:
    bool isValid(string word) {
        int vowel=0,consonant=0;
        for(char ch:word){
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A'|| ch=='E'|| ch=='I' || ch=='O' || ch=='U'){
                    vowel++;
                }
                else consonant++;
            }
            else if( ch>='0' && ch<='9')continue;
            else return false;
        }
        cout<<word.size()<<" "<<vowel<<" "<<consonant;
        return (vowel>0 && consonant>0 && word.size()>=3);
    }
};